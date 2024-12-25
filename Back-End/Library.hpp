//
//  Library.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include "IUser.hpp"
#include "Iadmin.hpp"
#include "Ilibrary.hpp"
#include "Request.hpp"
#include "Book.hpp"
#include "Bookshelf.hpp"
#include "PhysicalBook.hpp"
#include "ElectronicBook.hpp"
#include "RequestQueue.hpp"
#include "Bookshelf.hpp"
#include "UserManager.hpp"


class LibrarySystem : public UserInterface, public AdminInterface, public LibraryInterface {
public:
    // Реализация функций интерфейса пользователя
    std::vector<Book*> getAvailableBooks() override;
    std::vector<Book*> getAvailableBooksByTitle(const std::string& searchString) override;
    void borrowBookById(int UserID, int bookId) override;
    std::vector<Book*> getBooksToReturn(int UserID) override;
    void returnBookById(int bookId) override;
    std::vector<Book*> getAllUserBooks(int UserID) override;

    // Реализация функций интерфейса администратора
    std::vector<Book*> getAllLibraryBooks() override;
    std::vector<Book*> getBooksByTitle(const std::string& searchString) override;
    void deleteBookById(int bookId) override;
    void addBook(Book::BookType type, const std::string& author, const std::string& title) override;
    void confirmRequest() override;
    void denyRequest() override;
    int getRequestQueueSize() override;
    std::string getFirstRequestDetails() override;

    // Реализация функций интерфейса библиотеки
    void pushUserRequest(const int ID, const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& email) override;
    User* getUserById(int userId) override;
    bool userExists(int userId) override;

    // Деструктор
    ~LibrarySystem() override;
    
    LibrarySystem();
private:
    RequestQueue Requests_;
    BookShelf Books_;
    UserManager Users_;
    
  
};


#endif // LIBRARY_SYSTEM_H
