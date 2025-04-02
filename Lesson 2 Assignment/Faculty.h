#pragma once
#include "User.h"

class Faculty : public User
{
private: 
	std::string status = "Faculty";

public: 
	Faculty(std::string name, std::vector<Book*> borrowedBooks);

	std::string getStatus();

};

