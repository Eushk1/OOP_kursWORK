//
//  RequestQueue.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#include "RequestQueue.hpp"
#include "ReturnRequest.hpp"
#include "BorrowRequest.hpp"
#include "UserRequest.hpp"
#include "UserManager.hpp"
#include "Book.hpp"

void RequestQueue::addReturnRequest(BookShelf& bookshelf, int bookId) {
    requests.push(std::make_shared<ReturnRequest>(bookshelf, bookId));
}

void RequestQueue::addBorrowRequest(BookShelf& bookshelf, int UserID, int bookId) {
    auto book = bookshelf.getBookById(bookId);
    if (!book) {
        throw std::runtime_error("Книга не найдена.");
    }
    
    if (book->getType() == Book::BookType::PHYSICAL) {
        bookshelf.getPhysicalBook(bookId)->setStatus(PhysicalBook::Status::ON_HOLD, UserID);
        requests.push(std::make_shared<BorrowRequest>(bookshelf, UserID, bookId));
    } else {
        bookshelf.getElectronicBook(bookId)->borrowBook(UserID);
    }
}

void RequestQueue::addUserRequest(const UserManager& users, const int ID, const std::string& lastName, const std::string& firstName,
                                   const std::string& nickname, const std::string& email) {
    requests.push(std::make_shared<UserRequest>(users, ID, lastName, firstName, nickname, email));
}

void RequestQueue::confirmRequest() {
    if (!requests.empty()) {
        requests.front()->confirm();
        requests.pop();
    } else {
        throw std::runtime_error("Нет запросов для подтверждения.");
    }
}

void RequestQueue::rejectRequest() {
    if (!requests.empty()) {
        requests.front()->reject();
        requests.pop();
    } else {
        throw std::runtime_error("Нет запросов для отклонения.");
    }
}

std::string RequestQueue::getFirstRequestInfo() const {
    if (requests.empty()) {
        return "Очередь пуста.";
    }
    return requests.front()->getInfo();
}

int RequestQueue::getRequestCount() const {
    return requests.size();
}
