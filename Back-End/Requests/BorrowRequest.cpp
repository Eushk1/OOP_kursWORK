//
//  BorrowRequest.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#include "BorrowRequest.hpp"

BorrowRequest::BorrowRequest(int bookId) : bookId(bookId) {}

std::string BorrowRequest::getInfo() const {
    return "Получение книги, ID: " + std::to_string(bookId);
}

void BorrowRequest::confirm() {
    std::cout << "Книга с ID " << bookId << " была успешно выдана." << std::endl;
}
