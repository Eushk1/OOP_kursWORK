#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book {
public:
    virtual ~Book() = default;
    virtual std::string getAuthor() const = 0;
    virtual std::string getTitle() const = 0;
    virtual int getId() const = 0;
    virtual bool isAvailable() const = 0;
    virtual void print() const = 0;
};

#endif // BOOK_H
