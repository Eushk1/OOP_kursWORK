//
//  Library.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 23.12.2024.
//

#include "Library.hpp"

std::vector<Book*> LibrarySystem::getAvailableBooks(const std::string& searchString) override{
    return allBooksForUser (const std::string& user);
}
