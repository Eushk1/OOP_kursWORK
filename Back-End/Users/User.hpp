//
//  User.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#ifndef User_hpp
#define User_hpp

#include <string>

enum class UserRole {
    Admin,
    Reader
};

class User {
public:
    User(); // Конструктор по умолчанию
    User(int id, const std::string& lastName, const std::string& firstName, const std::string& username, const std::string& email, UserRole role = UserRole::Reader);

    UserRole getRole() const;
    std::string roleToString() const;

    // Методы для получения данных пользователя
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getUsername() const;
    std::string getEmail() const;

private:
    int user_id;
    std::string last_name;
    std::string first_name;
    std::string username;
    std::string email;
    UserRole role;
};

#endif /* User_hpp */
