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

class RequestQueue{
public:
    void addReturnRequest(int bookId);
    void addBorrowRequest(int bookId);
    void addUserRequest(const std::string& lastName, const std::string& firstName,
                        const std::string& nickname, const std::string& email);
    void confirmRequest();
    void rejectRequest();
    std::string getFirstRequestInfo() const;
    size_t getRequestCount() const;
private:
    std::queue<std::shared_ptr<Request>> requests;
};

#endif /* RequestQueue_hpp */
