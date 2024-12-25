//
//  UserRequest.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#include "UserRequest.hpp"

UserRequest::UserRequest(UserManager& users,const int ID, const std::string& lastName, const std::string& firstName,
                         const std::string& nickname, const std::string& email)
    : lastName(lastName), firstName(firstName), nickname(nickname), email(email), users(users), ID(ID) {}

std::string UserRequest::getInfo() const {
    return "Запрос добавления пользователя: " + lastName + " " + firstName;
}

void UserRequest::confirm() {
    users.addUser(ID, lastName, firstName, nickname, email);
}

void UserRequest::reject(){
    
}
