//
//  Bookshelf.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#include "Bookshelf.hpp"
#include "PhysicalBook.hpp"
#include "ElectronicBook.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void BookShelf::addPhysicalBook(const std::string& author, const std::string& title) {
    books_.emplace_back(std::make_unique<PhysicalBook>(author, title, nextId_++));
}

void BookShelf::addElectronicBook(const std::string& author, const std::string& title) {
    books_.emplace_back(std::make_unique<ElectronicBook>(author, title, nextId_++));
}

std::vector<Book*> BookShelf::availableBooks(const std::string& query) {
    std::vector<Book*> result;
    for (const auto& book : books_) {
        if (book->isAvailable() && (book->getAuthor().find(query) != std::string::npos ||
                                    book->getTitle().find(query) != std::string::npos)) {
            result.push_back(book.get());
        }
    }
    sortBooks(result);
    return result;
}

std::vector<Book*> BookShelf::availablePhysicalBooksForUser (const std::string& user) {
    std::vector<Book*> result;
    for (const auto& book : books_) {
        if (auto physicalBook = dynamic_cast<PhysicalBook*>(book.get())) {
            if (!physicalBook->isAvailable() && physicalBook->getUser () == user) {
                result.push_back(book.get());
            }
        }
    }
    sortBooks(result);
    return result;
}

std::vector<Book*> BookShelf::allBooksForUser (const std::string& user) {
    std::vector<Book*> result;
    for (const auto& book : books_) {
        if (book->isAvailable()) {
            result.push_back(book.get());
        } else {
            auto physicalBook = dynamic_cast<PhysicalBook*>(book.get());
            if (physicalBook && physicalBook->getUser () == user) {
                result.push_back(book.get());
            }
        }
    }
    sortBooks(result);
    return result;
}


std::vector<Book*> BookShelf::allBooks() {
    std::vector<Book*> result;
    for (const auto& book : books_) {
        result.push_back(book.get());
    }
    sortBooks(result);
    return result;
}

std::vector<Book*> BookShelf::booksByTitle(const std::string& query) {
    std::vector<Book*> result;
    for (const auto& book : books_) {
        if (book->getAuthor().find(query) != std::string::npos ||
            book->getTitle().find(query) != std::string::npos) {
            result.push_back(book.get());
        }
    }
    sortBooks(result);
    return result;
}

void BookShelf::updateElectronicBooks() {
    for (const auto& book : books_) {
        if (auto electronicBook = dynamic_cast<ElectronicBook*>(book.get())) {
            electronicBook->updateBorrowedUsers();
        }
    }
}

void BookShelf::removeBook(int id) {
    books_.erase(std::remove_if(books_.begin(), books_.end(),
        [id](const std::unique_ptr<Book>& book) { return book->getId() == id; }), books_.end());
}

void BookShelf::sortBooks(std::vector<Book*>& books) {
    std::sort(books.begin(), books.end(), [](Book* a, Book* b) {
        if (a->getAuthor() != b->getAuthor()) {
            return a->getAuthor() < b->getAuthor();
        }
        return a->getTitle() < b->getTitle();
    });
}


void BookShelf::saveBooksToFile(const std::string& filename) const {
        json j;
        for (const auto& book : books_) {
            json bookJson;
            bookJson["id"] = book->getId();
            bookJson["title"] = book->getTitle();
            bookJson["author"] = book->getAuthor();
            bookJson["status"] = book->isAvailable() ? "Available" : "Unavailable";

            if (auto physicalBook = dynamic_cast<PhysicalBook*>(book.get())) {
                bookJson["user"] = physicalBook->getUser ();
            } else {
                bookJson["user"] = nullptr; // Для электронных книг или других типов
            }

            j.push_back(bookJson);
        }

        std::ofstream ofs(filename);
        if (ofs.is_open()) {
            ofs << j.dump(4); // Форматирование с отступами
            ofs.close();
            std::cout << "Books saved to " << filename << std::endl;
        } else {
            std::cerr << "Could not open file " << filename << " for writing." << std::endl;
        }
    }

    // Метод для загрузки книг из файла book.txt
void BookShelf::loadBooksFromFile(const std::string& filename) {
        std::ifstream ifs(filename);
        if (ifs.is_open()) {
            json j;
            ifs >> j;

            for (const auto& bookJson : j) {
                // Здесь вы можете создать экземпляры книг на основе загруженных данных
                // Например, создадим физическую книгу
                std::string title = bookJson["title"];
                std::string author = bookJson["author"];
                int id = bookJson["id"];
                PhysicalBook* book = new PhysicalBook(author, title, id);
                
                // Устанавливаем статус книги
                if (bookJson["status"] == "Available") {
                    book->setStatus(PhysicalBook::AVAILABLE);
                } else {
                    book->setStatus(PhysicalBook::UNAVAILABLE, bookJson["user"]);
                }

                // Добавьте книгу в вашу коллекцию
                books_.emplace_back(book);
            }

            ifs.close();
            std::cout << "Books loaded from " << filename << std::endl;
        } else {
            std::cerr << "Could not open file " << filename << " for reading." << std::endl;
        }
    }
