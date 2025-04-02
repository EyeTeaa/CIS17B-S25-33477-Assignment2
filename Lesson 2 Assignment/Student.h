#pragma once
#include "User.h"

class Student : public User
{
private: 
	std::string status = "Student";

public: 
	Student(std::string name, std::vector<Book*> borrowedBooks); 

	std::string getStatus(); 

};

