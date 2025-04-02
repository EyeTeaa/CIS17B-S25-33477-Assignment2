
#include <iostream>
#include "Book.h"
#include "Library.h"
#include "User.h"



int main()
{
    std::cout << "Hello World!\n";
    Library& library = Library::getInstance();
    library.homeSelection();

}