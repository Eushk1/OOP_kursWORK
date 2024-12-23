//
//  Iadmin.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#ifndef ADMIN_INTERFACE_H
#define ADMIN_INTERFACE_H

#include <vector>
#include "Book.hpp"
#include "Bookshelf.hpp"
#include "PhysicalBook.hpp"
#include "ElectronicBook.hpp"
#include <string>

// Интерфейс администратора
class AdminInterface {
public:
    virtual std::vector<Book*> getAllLibraryBooks() = 0;
    virtual std::vector<Book*> getBooksByTitle(const std::string& searchString) = 0;
    virtual void deleteBookById(int bookId) = 0;
    virtual void addBook(const std::string& author, const std::string& title) = 0;
    virtual void confirmRequest() = 0;
    virtual void denyRequest() = 0;
    virtual int getRequestQueueSize() = 0;
    virtual std::string getFirstRequestDetails() = 0;
    virtual void pushUserRequest(const std::string& firstName, const std::string& lastName, const std::string& nickname, int userId) = 0;
    virtual std::string getUserById(int userId) = 0;
    virtual bool userExists(int userId) = 0;

    virtual ~AdminInterface() = default; // Виртуальный деструктор
};

#endif // ADMIN_INTERFACE_H

