//
//  ElectronicBook.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#ifndef ELECTRONICBOOK_H
#define ELECTRONICBOOK_H

#include "Book.hpp"
#include <string>
#include <unordered_map>

class ElectronicBook : public Book {
public:
    ElectronicBook(std::string author, std::string title, int id);
    void borrowBook(const std::string& user);
    void updateBorrowedUsers();

    std::string getAuthor() const override;
    std::string getTitle() const override;
    int getId() const override;
    bool isAvailable() const override;
    void print() const override;

private:
    std::string currentDateTime() const;

    std::string author_;
    std::string title_;
    int id_;
    std::unordered_map<std::string, std::string> borrowedUsers_;
};

#endif // ELECTRONICBOOK_H

