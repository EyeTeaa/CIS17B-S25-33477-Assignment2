#pragma once
#include <string>


class Book
{
private: 
	std::string title; 
	std::string author; 
	std::string ISBN; 
	bool availability; 

public: 
	//constructors 
	Book(std::string title, std::string author, std::string ISBN, bool availability);

	//accessors 
	std::string getTitle();
	std::string getAuthor(); 
	std::string getISBN(); 
	bool getAvailability(); 

	//mutators 
	void setTitle(std::string title);
	void setAuthor(std::string author); 
	void setISBN(std::string ISBN); 
	void setAvailability(bool availability); 

};
