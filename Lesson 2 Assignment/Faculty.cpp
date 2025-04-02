#include "Faculty.h"

Faculty::Faculty(std::string name, std::vector<Book*> borrowedBooks) : 
	User(name,borrowedBooks)
{
}

std::string Faculty::getStatus()
{
	return status; 
}