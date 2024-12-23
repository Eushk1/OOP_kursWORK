//
//  UserManager.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#ifndef UserManager_hpp
#define UserManager_hpp

#include <unordered_map>
#include <stdexcept>
#include <string>
#include "User.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

class UserManager {
public:
    void addUser (int id, const std::string& lastName, const std::string& firstName, const std::string& username, const std::string& email, UserRole role = UserRole::Reader);
    bool userExists(int id) const;
    std::string getUserRole(int id) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::unordered_map<int, User> users;
};

#endif /* UserManager_hpp */
