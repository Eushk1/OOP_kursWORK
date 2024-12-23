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

void RequestQueue::addReturnRequest(int bookId) {
    requests.push(std::make_shared<ReturnRequest>(bookId));
}

void RequestQueue::addBorrowRequest(int bookId) {
    requests.push(std::make_shared<BorrowRequest>(bookId));
}

void RequestQueue::addUserRequest(const std::string& lastName, const std::string& firstName,
                                   const std::string& nickname, const std::string& email) {
    requests.push(std::make_shared<UserRequest>(lastName, firstName, nickname, email));
}

void RequestQueue::confirmRequest() {
    if (!requests.empty()) {
        requests.front()->confirm(); // Вызываем метод confirm() для первой заявки
        requests.pop(); // Удаляем первую заявку из очереди
    }
}

void RequestQueue::rejectRequest() {
    if (!requests.empty()) {
        requests.pop(); // Удаляем первую заявку из очереди
    }
}

std::string RequestQueue::getFirstRequestInfo() const {
    if (requests.empty()) {
        return "Очередь пуста.";
    }
    return requests.front()->getInfo(); // Получаем информацию о первой заявке
}

size_t RequestQueue::getRequestCount() const {
    return requests.size(); // Возвращаем количество заявок в очереди
}
