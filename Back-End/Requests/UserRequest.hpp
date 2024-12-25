//
//  UserRequest.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 22.12.2024.
//

#ifndef UserRequest_hpp
#define UserRequest_hpp

#include "Request.hpp"
#include <iostream>
#include "UserManager.hpp"

class UserRequest : public Request {
public:
    UserRequest(UserManager& users,const int ID, const std::string& lastName, const std::string& firstName,
                const std::string& nickname, const std::string& email);
    std::string getInfo() const override;
    void confirm() override;
    void reject() override;


private:
    std::string lastName;
    std::string firstName;
    std::string nickname;
    std::string email;
    int ID;
    UserManager& users;
};

#endif /* UserRequest_hpp */
