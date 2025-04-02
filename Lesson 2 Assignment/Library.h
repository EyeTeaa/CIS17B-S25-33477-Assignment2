#pragma once 
#include "Book.h"
#include "User.h"
#include "Faculty.h"
#include "Student.h"
#include "vector"
#include <unordered_map>






class Library
{
private: 
    Library(); //private constructor so i only have once instance 
    std::vector<Book> bookList = {};
    std::vector<User> userList = {};
    std::unordered_map<Book*, User*> userBorrowedBooks;

public:

    //instead of a constructor, only return the single instance of library
    static Library& getInstance(); 


    void homeMenu(); 
    void homeSelection(); 

    
    void manageBooks(); 
    void manageBooksMenu();
    void addBook(); 
    void editBook(); 
    bool editBookProcess(std::vector<Book*> bookRefs); 
    void removeBook(); 
    bool removeBookProcess(std::vector<Book*> bookRefs); 
    Book* bookSelection(std::vector<Book*> bookRefs); 


    void manageUsers(); 
    void manageUsersMenu(); 
    void addUser(); 
    void editUser(); 
    bool editUserProcess(std::vector<User*> userRefs); 
    void removeUser(); 
    bool removeUserProcess(std::vector<User*> userRefs);
    User* userSelection(std::vector<User*> userRefs);

    void manageTransactions(); 
    void manageTransactionsMenu(); 
    void checkOutBook(); 
    void checkInBook(); 
    void listAllBooks(); 
    void listAllUsers(); 


    int inputValidationMenu(int lower, int upper); 



};