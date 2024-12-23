//
//  Request.hpp
//  KursWork_OOP_Back-end
//
//  Created by Егор on 21.12.2024.
//

#ifndef Request_hpp
#define Request_hpp

#include <string>

class Request {
public:
    virtual ~Request() = default; // Виртуальный деструктор
    virtual std::string getInfo() const = 0; // Чисто виртуальный метод для получения информации о заявке
    virtual void confirm() = 0; // Чисто виртуальный метод для обработки подтверждения заявки
};

#endif /* Request_hpp */
