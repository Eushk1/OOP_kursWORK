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
#include "UserManager.hpp"
#include "Bookshelf.hpp"

class BorrowRequest : public Request {
public:
    BorrowRequest(BookShelf& bookshelf, int UserID, int bookId);
    std::string getInfo() const override;
    void confirm() override;
    void reject() override;


private:
    int bookId;
    int UserID;
    BookShelf& bookshelf;
};

#endif /* BorrowRequest_hpp */
