//
//  PhysicalBook.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#ifndef PHYSICALBOOK_H
#define PHYSICALBOOK_H

#include "Book.hpp"
#include <string>

class PhysicalBook : public Book {
public:
    enum Status { AVAILABLE, UNAVAILABLE, ON_HOLD };

    PhysicalBook(std::string author, std::string title, int id);
    void setStatus(Status status, const std::string& user = "", const std::string& date = "");
    
    std::string getAuthor() const override;
    std::string getTitle() const override;
    std::string getUser () const;
    int getId() const override;
    bool isAvailable() const override;
    void print() const override;

private:
    std::string statusToString() const;

    std::string author_;
    std::string title_;
    int id_;
    Status status_;
    std::string user_;
    std::string date_;
};

#endif // PHYSICALBOOK_H

