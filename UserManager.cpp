//
//  UserManager.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#include "UserManager.hpp"

void UserManager::addUser (int id, const std::string& lastName, const std::string& firstName, const std::string& username, const std::string& email, UserRole role) {
    if (users.find(id) != users.end()) {
        throw std::invalid_argument("Пользователь с таким ID уже существует.");
    }
    users[id] = User(id, lastName, firstName, username, email, role);
}

bool UserManager::userExists(int id) const {
    return users.find(id) != users.end();
}

std::string UserManager::getUserRole(int id) const {
    auto it = users.find(id);
    if (it != users.end()) {
        return it->second.roleToString();
    } else {
        throw std::invalid_argument("Пользователь с таким ID не найден.");
    }
}

void UserManager::saveToFile(const std::string& filename) const {
    nlohmann::json jsonData;

    for (const auto& pair : users) {
        const User& user = pair.second;
        jsonData["users"].push_back({
            {"id", pair.first},
            {"last_name", user.getLastName()},
            {"first_name", user.getFirstName()},
            {"username", user.getUsername()},
            {"email", user.getEmail()},
            {"role", user.roleToString()}
        });
    }

    std::ofstream file(filename);
    if (file.is_open()) {
        file << jsonData.dump(4);
        file.close();
    } else {
        throw std::runtime_error("Не удалось открыть файл для записи.");
    }
}

void UserManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        nlohmann::json jsonData;
        file >> jsonData;

        for (const auto& item : jsonData["users"]) {
            int id = item["id"];
            std::string lastName = item["last_name"];
            std::string firstName = item["first_name"];
            std::string username = item["username"];
            std::string email = item["email"];
            UserRole role = (item["role"] == "Admin") ? UserRole::Admin : UserRole::Reader;

            if (users.find(id) == users.end()) {
                addUser (id, lastName, firstName, username, email, role);
            } else {

            }
        }
        file.close();
    } else {
        throw std::runtime_error("Не удалось открыть файл для чтения.");
    }
}
