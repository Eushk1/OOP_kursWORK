//
//  ReturnRequest.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 21.12.2024.
//

#ifndef ReturnRequest_hpp
#define ReturnRequest_hpp

#include "Request.hpp"
#include <iostream>
#include "UserManager.hpp"
#include "Bookshelf.hpp"

class ReturnRequest : public Request {
public:
    ReturnRequest(BookShelf& bookshelf, int bookId);
    std::string getInfo() const override;
    void confirm() override;
    void reject() override;
    
private:
    int bookId;
    BookShelf& bookshelf;
};

#endif /* ReturnRequest_hpp */
