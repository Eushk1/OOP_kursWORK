//
//  UserRequest.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#include "UserRequest.hpp"

UserRequest::UserRequest(const std::string& lastName, const std::string& firstName,
                         const std::string& nickname, const std::string& email)
    : lastName(lastName), firstName(firstName), nickname(nickname), email(email) {}

std::string UserRequest::getInfo() const {
    return "Добавление пользователя: " + lastName + " " + firstName;
}

void UserRequest::confirm() {
    std::cout << "Пользователь " << lastName << " " << firstName << " был успешно добавлен." << std::endl;
}
