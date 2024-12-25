//
//  User.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#include "User.hpp"


User ::User () : user_id(0), last_name(""), first_name(""), username(""), email(""), role(UserRole::Reader) {}

User ::User (int id, const std::string& lastName, const std::string& firstName, const std::string& username, const std::string& email, UserRole role)
    : user_id(id), last_name(lastName), first_name(firstName), username(username), email(email), role(role) {}

UserRole User::getRole() const {
    return role;
}

User* User::getPointer() {
        return this; 
}

std::string User::roleToString() const {
    switch (role) {
        case UserRole::Admin:
            return "Admin";
        case UserRole::Reader:
            return "Reader";
        default:
            return "Unknown";
    }
}

std::string User::getLastName() const {
    return last_name;
}

std::string User::getFirstName() const {
    return first_name;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getEmail() const {
    return email;
}

