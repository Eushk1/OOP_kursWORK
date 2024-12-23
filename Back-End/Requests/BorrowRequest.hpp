//
//  BorrowRequest.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#ifndef BorrowRequest_hpp
#define BorrowRequest_hpp

#include "Request.hpp"
#include <iostream>

class BorrowRequest : public Request {
public:
    BorrowRequest(int bookId);
    std::string getInfo() const override;
    void confirm() override;

private:
    int bookId;
};

#endif /* BorrowRequest_hpp */
