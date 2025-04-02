#include "Library.h"
#include <iostream>
using namespace std; 




Library::Library() {}; //constructor (private)


Library& Library::getInstance()
{
    static Library instance;
    return instance;
}



void Library::homeMenu()
{
    cout << "Welcome to the Library:\n" <<
        "1. Manage Books\n" <<
        "2. Manage Users\n" <<
        "3. Manage Transactions\n" << 
        "4. Exit\n"; 
}

void Library::homeSelection()
{
    while (true)
    {
        homeMenu();
        int response = inputValidationMenu(1, 4);
        switch (response)
        {
        case 1: manageBooks();
            break;
        case 2: manageUsers();
            break;
        case 3: manageTransactions();
            break;
        case 4: cout << "Thank you for using the Library System!";
            return;
        }
    }
}




/*manage books section*/
void Library::manageBooksMenu()
{
    cout << "> Manage Books:\n" << 
        "> 1. Add a Book\n" << 
        "> 2. Edit a Book\n" << 
        "> 3. Remove a Book\n" << 
        "> 4. Go Back\n";
}

void Library::manageBooks()
{
    while (true)
    {
        manageBooksMenu();
        int response = inputValidationMenu(1, 4);
        switch (response)
        {
        case 1: addBook();
            break;
        case 2: editBook();
            break;
        case 3: removeBook();
            break;
        case 4: 
            return;
        }
    }
}

void Library::addBook()
{
    string title, author, isbn; 
    cout << ">> Add a Book:\n"; 

    cout << ">> Enter the Title(0 to cancel) : "; 
    getline(cin, title);
    if (title == "0") 
    {
        manageBooksMenu(); 
        return;  // Exit the function if user cancels
    }


    cout << ">> Enter the Author(0 to cancel) : "; 
    getline(cin, author);
    if (author == "0")
    {
        return;  // Exit the function if user cancels
    }


    cout << ">> Enter the ISBN(0 to cancel) : "; 
    getline(cin, isbn); 
    if (isbn == "0")
    {

        return;  // Exit the function if user cancels
    }


    bookList.push_back(Book(title, author, isbn, true)); 
    cout << "> Book Added\n"; 

    return; 

}


void Library::editBook()
{
    string title;
    vector<Book*> bookReferences;
    bool foundBook = false; 
    bool bookEdited = false; 

    cout << ">> Edit a book:\n"; 
    if (bookList.size() == 0) // checking if there are books in the library
    {
        cout << "\n The book list is empty\n\n";  
        return; 
    } 

    // user enters the title 
    cout << ">> Enter the title(0 to cancel) : "; 
    getline(cin, title); 
    if (title == "0")
    {

        return; 
    }
 
    // a list of references is curated for books with the same title
    for (int i = 0; i < bookList.size(); i++) 
    {
        if (bookList[i].getTitle() == title) 
        {
            foundBook = true; 
            bookReferences.push_back(&bookList[i]); 
        }
    }

    // if there were no books matching that title 
    if (foundBook == false)
    {
        cout << "Book was not found\n"; 

        return; 
    }
    else // there were matching titles 
    {
        bookEdited = editBookProcess(bookReferences); 
    }

    if (bookEdited)
    {
        cout << "The book has been edited"; 
        return; 
    }
    else
    {
        cout << "No books have been edited"; 
        return; 
    }
}// end editBook 


bool Library::editBookProcess(vector<Book*> bookRefs)
{
    Book* bookToEdit = nullptr; // Pointer to selected book
    bool edited = false; 
    int choice; 
    string tempTitle, tempAuthor, tempISBN = "";

    //choosing the book if there are more than one or just one with same title
    bookToEdit = bookSelection(bookRefs);

    // time to edit the selected book here 
    while (true)
    {
        cout << ">> Editing book titled: " << bookToEdit->getTitle() << "\n";
        cout << "by author: " << bookToEdit->getAuthor() << "\n";
        cout << "\n";
        cout << "Indicate with an int your choice\n"; 
        cout << ">> 1. Title\n";
        cout << ">> 2. Author\n";
        cout << ">> 3. ISBN\n";
        cout << "<< 4. Exit\n";
        choice = inputValidationMenu(1, 4);

        switch (choice)
        {
        case 1: // changing the title 
            cout << ">> Enter the new title (0 to cancel) : ";
            cin.ignore();
            getline(cin, tempTitle);
            if (tempTitle != "0")
            {
                edited = true;
                bookToEdit->setTitle(tempTitle);
                cout << "Title changed successfully\n"; 
            }
            else
            {
                return edited;
            }
            break;
        case 2: //changing the author 
            cout << ">> Enter the new author (0 to cancel) : ";
            cin.ignore();
            getline(cin, tempAuthor);
            if (tempAuthor != "0")
            {
                edited = true;
                bookToEdit->setAuthor(tempAuthor);
                cout << "Author changed successfully\n"; 
            }
            else
            {
                return edited;
            }
            break;
        case 3:  // changing the ISBN
            cout << ">> Enter the new ISBN (0 to cancel) : ";
            cin.ignore();
            getline(cin, tempISBN);
            if (tempISBN != "0")
            {
                edited = true;
                bookToEdit->setISBN(tempISBN);
                cout << "ISBN changed successfully\n"; 
            }
            else
            {
                return edited; 
            }
            break;
        case 4: // exit editing book 
            return edited;

        }

    }

}


void Library::removeBook()
{
    string title;
    vector<Book*> bookReferences;
    bool foundBook = false;
    bool bookRemoved = false;

    cout << ">> Remove a book:\n";
    if (bookList.size() == 0) // checking if there are books in the library
    {
        cout << "\n The book list is empty\n\n";

        return;
    }

    // user enters the title 
    cout << ">> Enter the title(0 to cancel) : ";
    getline(cin, title);
    if (title == "0")
    {

        return;
    }

    // a list of references is curated for books with the same title
    for (int i = 0; i < bookList.size(); i++)
    {
        if (bookList[i].getTitle() == title)
        {
            foundBook = true;
            bookReferences.push_back(&bookList[i]);
        }
    }

    // if there were no books matching that title 
    if (foundBook == false)
    {
        cout << "Book was not found\n";

        return;
    }
    else // there were matching titles 
    {
        bookRemoved = removeBookProcess(bookReferences);
    }

    if (bookRemoved)
    {
        cout << "The book has been removed";
        return;
    }
    else
    {
        cout << "No books have been removed";
        return;
    }

}

bool Library::removeBookProcess(vector<Book*> bookRefs)
{
    Book* bookToRemove = nullptr; 
    int choice; 
    bookToRemove = bookSelection(bookRefs); 

    cout << "This is the indicated book: \n";
    cout << bookToRemove->getTitle() << "\n";
    cout << bookToRemove->getAuthor() << "\n"; 
    cout << bookToRemove->getISBN() << "\n"; 

    cout << "Enter '1' to remove book, '2' to cancel: \n"; 
    choice = inputValidationMenu(1, 2); 

    if (choice == 1)
    {
        for (auto it = bookList.begin(); it != bookList.end(); ++it)
        {
            if (it->getISBN() == bookToRemove->getISBN()) // Compare by ISBN
            {
                bookList.erase(it);
                return true;
            }
        }
    }
    else
    {
        return false; 

    }

    return false; 
}



Book* Library::bookSelection(vector<Book*> bookRefs)
{
    Book* selectedBook = nullptr; 

    if (bookRefs.size() > 1)
    {
        cout << "There are more than one book with the same title";
        for (int i = 0; i < bookRefs.size(); i++)
        {
            cout << i + 1 << ". ";
            cout << "Title: " << bookRefs[i]->getTitle() << "\n";
            cout << "Author: " << bookRefs[i]->getAuthor() << "\n";
            cout << "ISBN: " << bookRefs[i]->getISBN() << "\n";
            cout << "\n\n";
        }

        cout << "Enter an int indicating the book you want to select";
        selectedBook = bookRefs[inputValidationMenu(1, bookRefs.size()) - 1];
    }
    else if (bookRefs.size() == 1)
    {
        selectedBook = bookRefs[0];
    }

    return selectedBook; 
}




void Library::manageUsersMenu()
{
    cout << "> Manage Users :\n" << 
        "> 1. Add a User\n" << 
        "> 2. Edit a User\n" << 
        "> 3. Remove a User\n" << 
        "> 4. Go Back\n"; 
}

void Library::manageUsers()
{
    while (true)
    {
        manageUsersMenu();
        int response = inputValidationMenu(1, 4);
        switch (response)
        {
        case 1: addUser();
            break;
        case 2: editUser();
            break;
        case 3: removeUser();
            break;
        case 4: 
            return;
        }
    }

}

void Library::addUser()
{
    int choice; 
    string name;
    cout << ">> Add a User:\n";

    cout << ">> Enter 1 for faculty, 2 for student (0 to cancel) : ";
    choice = inputValidationMenu(0, 2); 
    if (choice == 0)
    {
        cout << "User not added\n\n";
        return;  // Exit the function if user cancels
    }
    else if (choice == 1) // adding a faculty 
    {
        cout << ">> Enter faculty name: "; 
        getline(cin, name); 
        userList.push_back(Faculty(name, {}));
    }
    else if (choice == 2) // adding a student 
    {
        cout << "Enter student name: "; 
        getline(cin, name); 
        userList.push_back(Student(name, {})); 
    }
    cout << "> User Added\n";
    return;

}

void Library::editUser()
{
    string name; 
    vector<User*> userReferences;
    bool foundUser = false;
    bool userEdited = false;

    cout << ">> Edit a User:\n";
    if (userList.size() == 0) // checking if there are users in the library
    {
        cout << "\n The user list is empty\n\n";
        return;
    }

    // user enters the name 
    cout << ">> Enter the name (0 to cancel) : ";
    getline(cin, name);
    if (name == "0")
    {
        return;
    }

    // a list of references is curated for users with the same name
    for (int i = 0; i < userList.size(); i++)
    {
        if (userList[i].getName() == name)
        {
            foundUser = true;
            userReferences.push_back(&userList[i]);
        }
    }

    // if there were no books matching that title 
    if (foundUser == false)
    {
        cout << "User was not found\n";
        return;
    }
    else // there were matching titles 
    {
        userEdited = editUserProcess(userReferences);
    }

    if (userEdited)
    {
        cout << "The user has been edited";
        return;
    }
    else
    {
        cout << "No users have been edited";
        return;
    }

}

bool Library::editUserProcess(vector<User*> userRefs)
{
    User* userToEdit = nullptr; // Pointer to selected user
    bool edited = false;
    int choice;
    string tempName = "";

    //choosing the user if there are more than one or just one with same name
    userToEdit = userSelection(userRefs);

    // time to edit the selected book here 
    while (true)
    {
        cout << ">> Editing user named: " << userToEdit->getName() << "\n";
        cout << "with ID: " << userToEdit->getUserID() << "\n";
        cout << "\n";
        cout << "Indicate with an int your choice\n";
        cout << ">> 1. Name\n";
        cout << "<< 2. Exit\n";
        choice = inputValidationMenu(1, 2);

        switch (choice)
        {
        case 1: // changing the name 
            cout << ">> Enter the new name (0 to cancel) : ";
            cin.ignore();
            getline(cin, tempName);
            if (tempName != "0")
            {
                edited = true;
                userToEdit->setName(tempName);
            }
            else
            {
                return edited; 
            }
            break;
        case 2: //exiting 
            return edited;

        }

    }

}

void Library::removeUser()
{
    string name;
    vector<User*> userReferences;
    bool foundUser = false;
    bool userRemoved = false;

    cout << ">> Remove a user:\n";
    if (userList.size() == 0) // checking if there are users in the library
    {
        cout << "\n The user list is empty\n\n";
        return;
    }

    // user enters the name 
    cout << ">> Enter the title(0 to cancel) : ";
    getline(cin, name);
    if (name == "0")
    {
        manageUsers();
        return;
    }

    // a list of references is curated for users with the same nname
    for (int i = 0; i < userList.size(); i++)
    {
        if (userList[i].getName() == name)
        {
            foundUser = true;
            userReferences.push_back(&userList[i]);
        }
    }

    // if there were no users matching that name 
    if (foundUser == false)
    {
        cout << "User was not found\n";        return;
    }
    else // there were matching titles 
    {
        userRemoved = removeUserProcess(userReferences);
    }

    if (userRemoved)
    {
        cout << "The user has been removed";
        return;
    }
    else
    {
        cout << "No users have been removed";
        return;
    }
}

bool Library::removeUserProcess(vector<User*> userRefs)
{
    User* userToRemove = nullptr;
    int choice;
    userToRemove = userSelection(userRefs);

    cout << "This is the indicated user: \n";
    cout << userToRemove->getName() << "\n";
    cout << userToRemove->getUserID() << "\n";

    cout << "Enter '1' to remove user, '2' to cancel: \n";
    choice = inputValidationMenu(1, 2);

    if (choice == 1)
    {
        for (auto it = userList.begin(); it != userList.end(); ++it)
        {
            if (it->getUserID() == userToRemove->getUserID()) // Compare by ID
            {
                userList.erase(it);
                return true;
            }
        }
    }
    else
    {
        return false;

    }

    return false;
}

User* Library::userSelection(vector<User*> userRefs)
{
    User* selectedUser = nullptr;

    if (userRefs.size() > 1)
    {
        cout << "There are more than one users with the same name";
        for (int i = 0; i < userRefs.size(); i++)
        {
            cout << i + 1 << ". ";
            cout << "Name: " << userRefs[i]->getName() << "\n";
            cout << "ID: " << userRefs[i]->getUserID() << "\n";
            cout << "\n\n";
        }

        cout << "Enter an int indicating the user you'd like to select";
        selectedUser = userRefs[inputValidationMenu(1, userRefs.size()) - 1];
    }
    else if (userRefs.size() == 1)
    {
        selectedUser = userRefs[0];
    }

    return selectedUser;
}




void Library::manageTransactionsMenu()
{
    cout << "> Manage Transactions:\n" <<
        "> 1. Check Out A Book\n" <<
        "> 2. Check In A Book\n" <<
        "> 3. List All Books\n" <<
        "> 4. List All Users\n" <<
        "> 5. Go Back\n";
}

void Library::manageTransactions()
{
    manageTransactionsMenu();
    int response = inputValidationMenu(1, 4);
    switch (response)
    {
    case 1: checkOutBook();
        break;
    case 2: checkInBook();
        break;
    case 3: listAllBooks();
        break;
    case 4: listAllUsers();
        break;
    case 5: 
        return;
    }
}

void Library::checkOutBook()
{
    string title;
    int userID; 
    bool foundBook, foundUser = false; 
    vector<Book*> bookReferences; 
    Book* bookToCheckout = nullptr; 
    User* userCheckingOut = nullptr; 

    cout << ">> Checking out a book: "; 
    if (bookList.size() == 0) // checking if there are books in the library
    {
        cout << "\n The book list is empty\n\n";
        return;
    }

    // user enters the title 
    cout << ">> Enter the title(0 to cancel) : ";
    getline(cin, title);
    if (title == "0")
    {
        return;
    }

    // a list of references is curated for books with the same title
    for (int i = 0; i < bookList.size(); i++)
    {
        if (bookList[i].getTitle() == title)
        {
            bookReferences.push_back(&bookList[i]);
        }
    }

    // if there were no books matching that title 
    if (bookReferences.size()  == 0)
    {
        cout << "Book does not exist\n";
        return;
    }
    else // there were matching titles 
    {
        bookToCheckout = bookSelection(bookReferences);
        if (bookToCheckout->getAvailability() == false)
        {
            cout << "Book is not available to checkout\n"; 
            return; 
        }
        else
        {
            foundBook = true;
        }
    }

    cout << ">> Enter the user ID checking out the book (0) to cancel: "; 
    cin.ignore(); 
    userID = inputValidationMenu(0, User::getIDGENERATOR()); 
    if (userID == 0)
    {
        return;  // Exit the function if user cancels
    }
    

    for (auto it = userList.begin(); it != userList.end(); ++it)
    {
        if (it->getUserID() == userID) // Compare by ID 
        {
            userCheckingOut = &(*it);
            foundUser = true; 
            return;
        }
    }

    if (!foundUser)
    {
        cout << "User not found in the library system\n";
        return; 
    }
    else
    {
        cout << ">> Checking out " << bookToCheckout->getTitle() << " for " << userCheckingOut->getName() << "\n";
        bookToCheckout->setAvailability(false);
        userCheckingOut->addBorrowedBook(bookToCheckout);
        userBorrowedBooks[bookToCheckout] = userCheckingOut;
        cout << ">> Book successfully checked out\n"; 
        return;
    }
}

void Library::checkInBook()
{
    string title;
    int userID;
    bool foundBook;
    vector<Book*> bookReferences;
    Book* bookToCheckIn = nullptr;
    User* userCheckingOut = nullptr;

    cout << ">> Checking in book \n";
    if (bookList.size() == 0) // checking if there are books in the library
    {
        cout << "\n The book list is empty\n\n";
        return;
    }

    // user enters the title 
    cout << ">> Enter the title(0 to cancel) : ";
    getline(cin, title);
    if (title == "0")
    {
        return;
    }

    // a list of references is curated for books with the same title
    for (int i = 0; i < bookList.size(); i++)
    {
        if (bookList[i].getTitle() == title)
        {
            bookReferences.push_back(&bookList[i]);
        }
    }

    // if there were no books matching that title 
    if (bookReferences.size() == 0)
    {
        cout << "Book does not exist\n";
        return;
    }
    else // there were matching titles 
    {
        bookToCheckIn = bookSelection(bookReferences);
        if (bookToCheckIn->getAvailability() == true)
        {
            cout << "Book is already available to checkout\n";
            return;
        }
        else
        {
            foundBook = true;
        }
    }

    auto it = userBorrowedBooks.find(bookToCheckIn);

    if (it != userBorrowedBooks.end()) 
    {
        cout << ">> Removing " << bookToCheckIn->getTitle() << " from " << it->second->getName() << "\n";
        bookToCheckIn->setAvailability(true);
        it->second->removeBorrowedBook(bookToCheckIn); 
        userBorrowedBooks.erase(it);
        cout << "Book successfully checked in \n"; 
        return;
    }

}

void Library::listAllBooks()
{
    cout << ">> Listing all books\n"; 
    int counter = 1; 
    for (auto it = bookList.begin(); it != bookList.end(); ++it)
    {
        cout << counter << ": " << it->getTitle() << "\n";
        cout << "Author: " << it->getAuthor() << "\n"; 
        cout << "ISBN: " << it->getISBN() << "\n"; 
        cout << "Available: " << it->getAvailability() << "\n"; 
        cout << "\n"; 
    }

    cout << "Theses are all of the books\n"; 
   
}

void Library::listAllUsers()
{
    cout << ">> Listing all users\n";
    int counter = 1; 
    for (auto it = userList.begin(); it != userList.end(); ++it)
    {
        cout << counter << ": " << it->getName() << "\n"; 
        cout << "ID: " << it->getUserID() << "\n"; 
        cout << "Borrowed Books : \n";
        if (it->getBorrowedBooks().size() == 0)
        {
            cout << "No borrowed books\n";
        }
        else
        {
            for (Book* book : it->getBorrowedBooks())
            {
                cout << "Title: " << book->getTitle() << "\n";
                cout << "Author: " << book->getAuthor() << "\n"; 
                cout << "ISBN: " << book->getISBN() << "\n"; 
                cout << "\n";
            }
            
        }
        
        cout << "\n\n";
    }
}





int Library::inputValidationMenu(int lower, int upper)
{
    int response = 0; 

    cout << "Enter your choice: "; 
    while (true)
    {
        try
        {
            if (!(cin >> response))
            {
                throw invalid_argument("Invalid Argument"); 
            }

            if (response < lower || response > upper)
            {
                throw invalid_argument("Invalid Argument"); 
            }

            break; 

        }
        catch (const invalid_argument& e)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter an int between" << lower << " and " << upper << ": "; 
 
        }

    }// end while 


    return response; 
}

