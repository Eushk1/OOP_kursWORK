//
//  Ilibrary.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#ifndef LIBRARY_INTERFACE_H
#define LIBRARY_INTERFACE_H

#include <string>
#include "UserManager.hpp"

class LibraryInterface {
public:
    virtual void pushUserRequest(const int ID, const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& email) = 0;
    virtual User* getUserById(int userId) = 0;
    virtual bool userExists(int userId) = 0;

    virtual ~LibraryInterface() = default; 
};

#endif // LIBRARY_INTERFACE_H

