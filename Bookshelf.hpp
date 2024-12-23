//
//  Bookshelf.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.hpp"
#include <vector>
#include <memory>
#include <string>

class BookShelf {
public:
    void addPhysicalBook(const std::string& author, const std::string& title);
    void addElectronicBook(const std::string& author, const std::string& title);
    std::vector<Book*> availableBooks(const std::string& query);
    std::vector<Book*> availablePhysicalBooksForUser (const std::string& user);
    std::vector<Book*> allBooksForUser (const std::string& user);
    std::vector<Book*> allBooks();
    std::vector<Book*> booksByTitle(const std::string& query);
    void updateElectronicBooks();
    void removeBook(int id);
    
    void saveBooksToFile(const std::string& filename) const;
    void loadBooksFromFile(const std::string& filename);
private:
    void sortBooks(std::vector<Book*>& books);

    std::vector<std::unique_ptr<Book>> books_;
    int nextId_ = 1;
};

#endif // LIBRARY_H

