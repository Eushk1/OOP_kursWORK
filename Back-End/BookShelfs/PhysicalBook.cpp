//
//  PhysicalBook.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#include "PhysicalBook.hpp"
#include <iostream>

PhysicalBook::PhysicalBook(std::string author, std::string title, int id)
    : author_(std::move(author)), title_(std::move(title)), id_(id), status_(AVAILABLE) {}

void PhysicalBook::setStatus(Status status, const std::string& user, const std::string& date) {
    status_ = status;
    user_ = user;
    date_ = date;
}

std::string PhysicalBook::getAuthor() const { return author_; }
std::string PhysicalBook::getTitle() const { return title_; }
std::string PhysicalBook::getUser () const {return user_;}
int PhysicalBook::getId() const { return id_; }
bool PhysicalBook::isAvailable() const { return status_ == AVAILABLE; }

void PhysicalBook::print() const {
    std::cout << "Physical Book - ID: " << id_ << ", Author: " << author_
              << ", Title: " << title_ << ", Status: " << statusToString()
              << (status_ != AVAILABLE ? ", User: " + user_ + ", Date: " + date_ : "") << "\n";
}

std::string PhysicalBook::statusToString() const {
    switch (status_) {
        case AVAILABLE: return "Available";
        case UNAVAILABLE: return "Unavailable";
        case ON_HOLD: return "On Hold";
    }
    return "Unknown";
}
