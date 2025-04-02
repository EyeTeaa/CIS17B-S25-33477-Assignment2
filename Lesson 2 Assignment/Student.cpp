#include "Student.h"


Student::Student(std::string name, std::vector<Book*> borrowedBooks) :
	User(name, borrowedBooks)
{
}

std::string Student::getStatus()
{
	return status; 
}