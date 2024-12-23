//
//  ElectronicBook.cpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#include "ElectronicBook.hpp"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

ElectronicBook::ElectronicBook(std::string author, std::string title, int id)
    : author_(std::move(author)), title_(std::move(title)), id_(id) {}

void ElectronicBook::borrowBook(const std::string& user) {
    borrowedUsers_[user] = currentDateTime();
}

void ElectronicBook::updateBorrowedUsers() {
    std::time_t now = std::time(nullptr);
    for (auto it = borrowedUsers_.begin(); it != borrowedUsers_.end();) {
        std::tm borrowedTime = {};
        std::istringstream ss(it->second);
        ss >> std::get_time(&borrowedTime, "%Y-%m-%d %H:%M:%S");
        std::time_t borrowedDate = std::mktime(&borrowedTime);
        double secondsDiff = std::difftime(now, borrowedDate);

        if (secondsDiff > 30 * 24 * 60 * 60) {
            std::cout << "User  " << it->first << " removed from electronic book ID " << id_ << "\n";
            it = borrowedUsers_.erase(it);
        } else {
            ++it;
        }
    }
}

std::string ElectronicBook::getAuthor() const { return author_; }
std::string ElectronicBook::getTitle() const { return title_; }
int ElectronicBook::getId() const { return id_; }
bool ElectronicBook::isAvailable() const { return true; }

void ElectronicBook::print() const {
    std::cout << "Electronic Book - ID: " << id_ << ", Author: " << author_
              << ", Title: " << title_ << ", Borrowed by: ";
    for (const auto& entry : borrowedUsers_) {
        std::cout << entry.first << " at " << entry.second << ", ";
    }
    std::cout << "\n";
}

std::string ElectronicBook::currentDateTime() const {
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

