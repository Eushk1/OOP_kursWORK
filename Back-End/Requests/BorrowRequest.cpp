//
//  BorrowRequest.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#include "BorrowRequest.hpp"

BorrowRequest::BorrowRequest(BookShelf& bookshelf, int UserID, int bookId) : UserID(UserID), bookId(bookId), bookshelf(bookshelf) {}

std::string BorrowRequest::getInfo() const {
    return "Получение книги, ID: " + std::to_string(bookId) + " Пользователем с ID: "+std::to_string(UserID);
}

void BorrowRequest::confirm() {
    std::time_t now = std::time(0);
    bookshelf.getPhysicalBook(bookId)->setStatus(PhysicalBook::Status::UNAVAILABLE,UserID,ctime(&now));
}

void BorrowRequest::reject(){
    bookshelf.getPhysicalBook(bookId)->setStatus(PhysicalBook::Status::AVAILABLE,-1);
}
