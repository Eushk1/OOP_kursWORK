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

class ReturnRequest : public Request {
public:
    ReturnRequest(int bookId);
    std::string getInfo() const override;
    void confirm() override;
    
private:
    int bookId;
};

#endif /* ReturnRequest_hpp */
