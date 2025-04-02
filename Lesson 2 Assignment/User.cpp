#include "User.h"
#include <string>

// all of the IDs are going to be based off of this static int
int User::IDGENERATOR = 0;

//constructor 
User::User(std::string name, std::vector<Book*> borrowedBooks)
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
std::vector<Book*> User::getBorrowedBooks()
{
	return borrowedBooks; 
}
int User::getIDGENERATOR()
{
	return IDGENERATOR; 
}

//mutators 
void User::setName(std::string name)
{
	this->name = name; 
}
void User::addBorrowedBook(Book* book)
{
	this->borrowedBooks.push_back(book); 
}
void User::removeBorrowedBook(Book* book)
{
	if (!book) return; 

	auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);

	if (it != borrowedBooks.end()) {
		borrowedBooks.erase(it);
	}
}
void User::setBorrowedBooks(std::vector<Book*> borrowedBooks)
{
	this->borrowedBooks = borrowedBooks; 
}