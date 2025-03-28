#include "User.h"
#include <string>

// all of the IDs are going to be based off of this static int
int User::IDGENERATOR = 0;

//constructor 
User::User(std::string name, std::vector<Book> borrowedBooks)
{
	this->name = name; 
	this->userID = IDGENERATOR + 1 ;
	IDGENERATOR = IDGENERATOR + 1; // increases it for the next user 
	this->borrowedBooks = borrowedBooks; 
}

//accessors 
std::string User::getName()
{
	return name; 
}
int User::getUserID()
{
	return userID; 
}
std::vector<Book> User::getBorrowedBooks()
{
	return borrowedBooks; 
}

//mutators 
void User::setName(std::string name)
{
	this->name = name; 
}
void User::setBorrowedBooks(std::vector<Book> borrowedBooks)
{
	this->borrowedBooks = borrowedBooks; 
}