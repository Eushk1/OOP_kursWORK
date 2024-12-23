//
//  IUser.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <vector>
#include <string>
#include "Book.hpp"
#include "Bookshelf.hpp"
#include "PhysicalBook.hpp"
#include "ElectronicBook.hpp"



// Интерфейс пользователя
class UserInterface {
public:
    virtual std::vector<Book*> getAvailableBooks(const std::string& searchString) = 0;
    virtual void reserveBookById(int bookId) = 0;
    virtual std::vector<Book*> getBooksToReturn() = 0;
    virtual void returnBookById(int bookId) = 0;
    virtual std::vector<Book*> getAllUserBooks() = 0;

    virtual ~UserInterface() = default; // Виртуальный деструктор
};

#endif // USER_INTERFACE_H
