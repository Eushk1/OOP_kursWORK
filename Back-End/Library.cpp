#include "Library.hpp"

std::vector<Book*> LibrarySystem::getAvailableBooks(){
    return Books_.availableBooks();
}

std::vector<Book*> LibrarySystem::getAvailableBooksByTitle(const std::string& searchString){
    return Books_.availableBooksByQuery(searchString);
}

void LibrarySystem::borrowBookById(int UserID, int bookId){
    Requests_.addBorrowRequest(Books_, UserID, bookId);
}

std::vector<Book*> LibrarySystem::getBooksToReturn(int UserID){
    return Books_.availablePhysicalBooksForUser(UserID);
}

void LibrarySystem::returnBookById(int bookId){
    Requests_.addReturnRequest(Books_, bookId);
}

std::vector<Book*> LibrarySystem::getAllUserBooks(int UserID){
    return Books_.allBooksForUser(UserID);
}

std::vector<Book*> LibrarySystem::getAllLibraryBooks(){
    return Books_.allBooks();
}

std::vector<Book*> LibrarySystem::getBooksByTitle(const std::string& searchString){
    return Books_.booksByTitle(searchString);
}

void LibrarySystem::deleteBookById(int bookId){
    Books_.removeBook(bookId);
}

void LibrarySystem::addBook(Book::BookType type,const std::string& author, const std::string& title){
    if(type==Book::BookType::PHYSICAL){
        Books_.addPhysicalBook(author, title);
    }else{
        Books_.addElectronicBook(author,title);
    }
}

void LibrarySystem::confirmRequest(){
    Requests_.confirmRequest();
}


void LibrarySystem::denyRequest(){
    Requests_.rejectRequest();
}

int LibrarySystem::getRequestQueueSize(){
    return Requests_.getRequestCount();
}

std::string LibrarySystem::getFirstRequestDetails(){
    return Requests_.getFirstRequestInfo();
}

void LibrarySystem::pushUserRequest(const int ID, const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& email){
    Requests_.addUserRequest(Users_,ID, lastName,firstName,nickname, email);
}

User* LibrarySystem::getUserById(int userId){
    return Users_.getUser(userId);
}


bool LibrarySystem::userExists(int userId){
    return Users_.userExists(userId);
}
                   
            
LibrarySystem::LibrarySystem()
    : Requests_(), // Инициализация очереди запросов
      Books_(),     // Инициализация полки с книгами
      Users_()      // Инициализация менеджера пользователей
{
    std::string fullPath = "/Users/Egor 1/Desktop/Прога курсовик 2 курс/КУрсовая ООП/KursWork_OOP_Back-end/users.json"; // Замените на нужный путь

    Users_.loadFromFile(fullPath);
}

// Деструктор
LibrarySystem::~LibrarySystem() {
    std::string fullPath = "/Users/Egor 1/Desktop/Прога курсовик 2 курс/КУрсовая ООП/KursWork_OOP_Back-end/users.json"; // Замените на нужный путь

    Users_.saveToFile(fullPath);
}

                   

                   
