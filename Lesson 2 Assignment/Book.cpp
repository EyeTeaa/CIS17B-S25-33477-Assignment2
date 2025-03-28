#include "Book.h"
#include <string>

//constructors 
Book::Book(std::string title, std::string author, std::string ISBN, bool availability)
{
	this->title = title;
	this->author = author; 
	this->ISBN = ISBN; 
	this->availability = availability; 
}

//accessors 
std::string Book::getTitle()
{
	return title; 
}
std::string Book::getAuthor()
{
	return author; 
}
std::string Book::getISBN()
{
	return ISBN; 
}
bool Book::getAvailability()
{
	return availability; 
}

//mutators 
void Book::setTitle(std::string title)
{
	this->title = title; 
}
void Book::setAuthor(std::string author)
{
	this->author = author; 
}
void Book::setISBN(std::string ISBN)
{
	this->ISBN = ISBN; 
}
void Book::setAvailability(bool availability)
{
	this->availability = availability; 
}