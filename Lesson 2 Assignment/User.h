#pragma once
#include <string>
#include <vector>
#include "Book.h"

//Represents a user with attributes such as name, userID, and a list of borrowed books. (note: UserID can be automatically generated).


class User
{
private: 
	static int IDGENERATOR;

	std::string name; 
	int userID; 
	std::vector<Book*> borrowedBooks; 

public: 
	//constructor 
	User(std::string name, std::vector<Book*> borrowedBooks); 

	//accessors 
	std::string getName(); 
	int getUserID(); 
	std::vector<Book*> getBorrowedBooks(); 
	static int getIDGENERATOR(); 


	//mutators 
	void setName(std::string name); 
	void setUserID(int userID); 
	void addBorrowedBook(Book* book); 
	void removeBorrowedBook(Book* book); 
	void setBorrowedBooks(std::vector<Book*> borrowedBooks);

};

