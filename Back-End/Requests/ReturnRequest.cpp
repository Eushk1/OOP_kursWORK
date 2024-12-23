//
//  ReturnRequest.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 21.12.2024.
//

#include "ReturnRequest.hpp"

ReturnRequest::ReturnRequest(int bookId) : bookId(bookId) {}

std::string ReturnRequest::getInfo() const {
    return "Сдача книги, ID: " + std::to_string(bookId);
}

void ReturnRequest::confirm() {
    std::cout << "Книга с ID " << bookId << " была успешно возвращена." << std::endl;
}
