//
//  ReturnRequest.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 21.12.2024.
//

#include "ReturnRequest.hpp"

ReturnRequest::ReturnRequest(BookShelf& bookshelf, int bookId) : bookId(bookId), bookshelf(bookshelf) {}

std::string ReturnRequest::getInfo() const {
    return "Сдача книги, ID: " + std::to_string(bookId);
}

void ReturnRequest::confirm() {
    bookshelf.getPhysicalBook(bookId)->setStatus(PhysicalBook::Status::AVAILABLE,-1);
}

void ReturnRequest::reject(){
    
}
