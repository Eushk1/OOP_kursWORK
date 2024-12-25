//
//  RequestQueue.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#ifndef RequestQueue_hpp
#define RequestQueue_hpp

#include "Request.hpp"
#include <queue>
#include <memory>
#include "Book.hpp"
#include "Bookshelf.hpp"
#include "UserManager.hpp"

class RequestQueue{
public:
    void addReturnRequest(BookShelf& bookshelf, int bookId);
    void addBorrowRequest(BookShelf& bookshelf, int UserID, int bookId);
    void addUserRequest(const UserManager& users, const int ID, const std::string& lastName, const std::string& firstName,
                                      const std::string& nickname, const std::string& email);
    void confirmRequest();
    void rejectRequest();
    std::string getFirstRequestInfo() const;
    int getRequestCount() const;
private:
    std::queue<std::shared_ptr<Request>> requests;
};

#endif /* RequestQueue_hpp */
