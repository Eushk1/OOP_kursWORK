//
//  Ilibrary.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#ifndef LIBRARY_INTERFACE_H
#define LIBRARY_INTERFACE_H

#include <string>

class LibraryInterface {
public:
    virtual void pushUserRequest(const std::string& firstName, const std::string& lastName, const std::string& nickname, int userId) = 0;
    virtual std::string getUserById(int userId) = 0;
    virtual bool userExists(int userId) = 0;

    virtual ~LibraryInterface() = default; // Виртуальный деструктор
};

#endif // LIBRARY_INTERFACE_H

