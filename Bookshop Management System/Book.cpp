#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <conio.h>
#include <limits>
#include <algorithm>

#include "Book.h"


Book::Book()
{
    top = nullptr;
    numItem = 0;
}

Book::~Book()
{
}

void Book::addBook()
{
    std::string newBookTitle;
    std::string newBookAuthor;
    std::string newBookIsbn;
    double newBookPrice;
    int newBookQuantity;
    bool endinsert = false;
    char addingAction;

    int numberNewBooks = 0;
    do
    {
        system("cls");
        std::cout << "============================================" << std::endl;
        std::cout << "Please key in the informations of new Books" << std::endl;
        std::cout << "============================================" << std::endl;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        std::cout << "\nBookName: ";
        std::getline(std::cin, newBookTitle);
        std::cout << "\nAuthor: ";
        std::getline(std::cin, newBookAuthor);
        std::cout << "\nISBN: ";
        std::getline(std::cin, newBookIsbn);

        // Input validation for price
        while (true) {
            std::cout << "\nPrice: ";
            std::cin >> newBookPrice;
            if (std::cin.fail() || newBookPrice <= 0) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input for price. Please enter a valid number." << std::endl;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer after reading double
                break;
            }
        }

        // Input validation for quantity
        while (true) {
            std::cout << "\nQuantity: ";
            std::cin >> newBookQuantity;
            if (std::cin.fail() || newBookQuantity <= 0) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input for quantity. Please enter a valid integer." << std::endl;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer after reading integer
                break;
            }
        }

        std::cout << "===========================================" << std::endl;

        Book::push(newBookTitle, newBookAuthor, newBookIsbn, newBookPrice, newBookQuantity);
        numberNewBooks++;

        std::cout << "The number of the books have added is " << numberNewBooks << std::endl;

        std::cout << "=============================================" << std::endl;
        std::cout << "\n\n1. Add Next";
        std::cout << "\n2. Undo";
        std::cout << "\n0. Confirm" << std::endl;

        std::cout << "Please choose your next action: ";

        std::cin >> addingAction;

        switch (addingAction) {
        case '1':
            std::cout << "\nPreparing for the next books..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            break;
        case '2':
            if (numberNewBooks != 0) {
                Book::pop();
                --numberNewBooks;
            }
            else {
                std::cout << "\nThere doesn't have any books in the lists" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            break;
        case '0':
            std::cout << "\nInserting the books into inventory..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "Insert completed!" << std::endl;
            endinsert = true;
        default:
            std::cout << "\nInvalid input, please try again..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            break;
        }
    } while (!endinsert);
}

void Book::ascendingAuthorInsertionSort()
{
    if (!top || !top->next) return; // No need to sort if list is empty or has only one element

    NODE* sorted = nullptr; // Start with an empty sorted list

    while (top) {
        NODE* pCurr = top;
        top = top->next;

        if (!sorted || sorted->author > pCurr->author) {
            // Insert at the beginning of the sorted list
            pCurr->next = sorted;
            sorted = pCurr;
        }
        else {
            // Insert in the correct position in the sorted list
            NODE* temp = sorted;
            while (temp->next && temp->next->author < pCurr->author) {
                temp = temp->next;
            }
            pCurr->next = temp->next;
            temp->next = pCurr;
        }
    }
    top = sorted;
}

void Book::ascendingTitleInsertionSort()
{
    if (!top || !top->next) return; // No need to sort if list is empty or has only one element

    NODE* sorted = nullptr; // Start with an empty sorted list

    while (top) {
        NODE* pCurr = top;
        top = top->next;

        if (!sorted || sorted->title > pCurr->title) {
            // Insert at the beginning of the sorted list
            pCurr->next = sorted;
            sorted = pCurr;
        }
        else {
            // Insert in the correct position in the sorted list
            NODE* temp = sorted;
            while (temp->next && temp->next->title < pCurr->title) {
                temp = temp->next;
            }
            pCurr->next = temp->next;
            temp->next = pCurr;
        }
    }
    top = sorted;
}

void Book::deleteBook()
{
    Book::displayBookTable();
    std::cout << "\n\nPlease enter the title of the book you want to delete: ";
    std::string target;
    std::cin.ignore(); // To clear the newline character from the buffer
    std::getline(std::cin, target);
    
    NODE* pCurr = top;
    NODE* prev = nullptr;

    while (pCurr != nullptr && pCurr->title != target)
    {
        prev = pCurr;
        pCurr = pCurr->next;
    }

    if (pCurr == nullptr)
    {
        std::cout << "Book with title \"" << target << "\" not found.\n";
        return;
    }

    if (prev == nullptr)
    {
        // The book to delete is the first node
        top = pCurr->next;
    }
    else
    {
        // The book to delete is not the first node
        prev->next = pCurr->next;
    }

    std::cout << "Book with title \"" << pCurr->title << "\" has been deleted.\n";
    delete pCurr;
    --numItem;
}

void Book::descendingAuthorInsertionSort()
{
    if (!top || !top->next)
    {
        return; // No need to sort if list is empty or has only one element
    }

    NODE* sorted = nullptr; // Start with an empty sorted list

    while (top)
    {
        NODE* pCurr = top;
        top = top->next;

        if (!sorted || sorted->author < pCurr->author)
        {
            // Insert at the beginning of the sorted list
            pCurr->next = sorted;
            sorted = pCurr;
        }
        else
        {
            // Insert in the correct position in the sorted list
            NODE* temp = sorted;
            while (temp->next && temp->next->author > pCurr->author) {
                temp = temp->next;
            }
            pCurr->next = temp->next;
            temp->next = pCurr;
        }
    }
    top = sorted;
}

void Book::descendingTitleInsertionSort()
{
    if (!top || !top->next) return; // No need to sort if list is empty or has only one element

    NODE* sorted = nullptr; // Start with an empty sorted list

    while (top) {
        NODE* pCurr = top;
        top = top->next;

        if (!sorted || sorted->title < pCurr->title) {
            // Insert at the beginning of the sorted list
            pCurr->next = sorted;
            sorted = pCurr;
        }
        else {
            // Insert in the correct position in the sorted list
            NODE* temp = sorted;
            while (temp->next && temp->next->title > pCurr->title) {
                temp = temp->next;
            }
            pCurr->next = temp->next;
            temp->next = pCurr;
        }
    }
    top = sorted;
}

void Book::displayBookTable()
{
    system("cls");
    NODE* pCurr = top;
    if (pCurr == nullptr) {
        std::cout << "The inventory is empty." << std::endl;
        _getch();
        return;
    }

    std::cout << "+-------------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                                             INVENTORY                                           |" << std::endl;
    std::cout << "+-----+------------------------------+--------------------+---------------+------------+----------+" << std::endl;
    std::cout << "| " << std::setw(3) << std::left << "No"
        << " | " << std::setw(28) << std::left << "Title"
        << " | " << std::setw(18) << std::left << "Author"
        << " | " << std::setw(13) << std::left << "ISBN"
        << " | " << std::setw(10) << std::left << "Price (RM)"
        << " | " << std::setw(8) << std::left << "Quantity"
        << " |" << std::endl;
    std::cout << "+-----+------------------------------+--------------------+---------------+------------+----------+" << std::endl;

    int bookNumber = 1;

    while (pCurr != nullptr) {
        std::cout << "| " << std::setw(3) << std::left << bookNumber
            << " | " << std::setw(28) << std::left << pCurr->title
            << " | " << std::setw(18) << std::left << pCurr->author
            << " | " << std::setw(13) << std::left << pCurr->ISBN
            << " | " << std::setw(10) << std::left << std::setprecision(2) << pCurr->price
            << " | " << std::setw(8) << std::left << pCurr->quantity
            << " |" << std::endl;
        std::cout << "+-----+------------------------------+--------------------+---------------+------------+----------+" << std::endl;

        pCurr = pCurr->next;
        bookNumber++;
    }
}

bool Book::empty()
{
    return (numItem == 0);
}

int Book::getNumberOfBooks()
{
    return numItem;
}

void Book::displayInventory() 
{
    char sortAction, orderAction, action;
    bool quitdisplay = false;
    Book::ascendingTitleInsertionSort();

    do
    {
        system("cls");
        Book::displayBookTable();
        if (Book::empty())
        {
            quitdisplay = true;
            break;
        }
        std::cout << "\n\n==============================" << std::endl;
        std::cout << "A. Settings                   " << std::endl;
        std::cout << "0. Exit                       " << std::endl;
        std::cout << "==============================" << std::endl;

        std::cout << "\nPLEASE CHOOSE YOUR ACTION: ";
        std::cin >> action;

        if ((action == 'A') || (action == 'a'))
        {
            system("cls");
            //settings
            std::cout << "==============================" << std::endl;
            std::cout << "           SORTING            " << std::endl;
            std::cout << "==============================" << std::endl;
            std::cout << "SORT BOOKS BY :               " << std::endl;
            std::cout << "A. Title                      " << std::endl;
            std::cout << "B. Author                     " << std::endl;

            std::cout << "\nPLEASE ENTER YOUR CHOICE: ";
            std::cin >> sortAction;

            switch (sortAction) {
            case 'A':
            case 'a': {
                //show books>title
                system("cls");
                std::cout << "==============================" << std::endl;
                std::cout << "             ORDER            " << std::endl;
                std::cout << "==============================" << std::endl;
                std::cout << "SORTING TITLE WITH :       " << std::endl;
                std::cout << "A. Ascending                  " << std::endl;
                std::cout << "B. Descending                 " << std::endl;

                std::cout << "\nPLEASE ENTER YOUR CHOICE: ";
                std::cin >> orderAction;

                switch (orderAction) {
                case 'A':
                case 'a':
                    //Show books>Title>Ascending
                    Book::ascendingTitleInsertionSort();
                    Book::displayBookTable();
                    system("cls");
                    break;
                case 'B':
                case 'b':
                    //Show books>Title>Descending
                    Book::descendingTitleInsertionSort();
                    Book::displayBookTable();
                    system("cls");
                    break;
                default:
                    std::cout << "\nInvalid Input, please try again..." << std::endl;
                    std::this_thread::sleep_for(chrono::milliseconds(500));
                    break;
                }

                system("cls");
                break;
            }
            case 'B':
            case 'b': {
                //Show books>Author
                system("cls");
                std::cout << "==============================" << std::endl;
                std::cout << "          ORDER           " << std::endl;
                std::cout << "==============================" << std::endl;
                std::cout << "SORTING AUTHOR WITH :      " << std::endl;
                std::cout << "A. Ascending                  " << std::endl;
                std::cout << "B. Descending                 " << std::endl;

                std::cout << "\nPLEASE ENTER YOUR CHOICE: ";
                std::cin >> orderAction;

                switch (orderAction) {
                case 'A':
                case 'a':
                    //Show books>Author>Ascending
                    Book::ascendingAuthorInsertionSort();
                    Book::displayBookTable();
                    system("cls");
                    break;

                case 'B':
                case 'b':
                    //Show books>Author>Descending
                    Book::descendingAuthorInsertionSort();
                    Book::displayBookTable();
                    system("cls");
                    break;
                default:
                    std::cout << "\nInvalid Input, please try again..." << std::endl;
                    std::this_thread::sleep_for(chrono::milliseconds(500));
                    break;
                }
                break;
            }
            default:
                std::cout << "\nInvalid Input, please try again..." << std::endl;
                std::this_thread::sleep_for(chrono::milliseconds(500));
                break;
            }
        }
        else if (action == '0')
        {
            quitdisplay = true;
            break;
        }
        else
        {
            system("cls");
            std::cout << "\nInvalid Input, please try again..." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }while (!quitdisplay);
}

void Book::inventoryMainPage()
{
    bool inventoryQuit = false;

    do
    {
        system("cls");

        char action;

        std::cout << "==============================" << std::endl;
        std::cout << "          INVENTORY           " << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "A. Show Books                 " << std::endl;
        std::cout << "B. Insert Books               " << std::endl;
        std::cout << "C. Edit Books                 " << std::endl;
        std::cout << "D. Delete Books               " << std::endl;
        std::cout << "E. Search for Books           " << std::endl;
        std::cout << "0. Exit                       " << std::endl;
        std::cout << "==============================" << std::endl;

        std::cout << "\nPLEASE ENTER YOUR CHOICE: ";
        std::cin >> action;

        switch (action)
        {
        case 'A':
        case 'a':
            Book::displayInventory();
            break;
        case 'B':
        case 'b':
            Book::addBook();
            break;
        case 'C':
        case 'c':
            Book::update();
            break;

        case 'D':
        case 'd':

            Book::deleteBook();
            break;
        case 'E':
        case 'e':
            {
                bool searchAgain = false;
                do {
                    Book::searchBook();
                    char searchOption;
                    std::cout << "Do you want to search for another book? (Y/N): ";
                    std::cin >> searchOption;
                    while (searchOption != 'Y' && searchOption != 'y' && searchOption != 'N' && searchOption != 'n') {
                        std::cout << "Invalid input. Please enter 'Y' or 'N': ";
                        std::cin >> searchOption;
                    }
                    searchAgain = (searchOption == 'Y' || searchOption == 'y');
                } while (searchAgain);
            }
            break;
        case '0':
            inventoryQuit = true;
            break;

        default:
            std::cout << "\nInvalid Input, please try again..." << std::endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            break;
        }
    } while (!inventoryQuit);
}

void Book::merchantMainPage()
{
    bool merchantQuit = false;

    do
    {
        system("cls");
        char action;
        std::cout << "==============================" << std::endl;
        std::cout << "          MERCHANT            " << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "A. Cashier" << std::endl;
        std::cout << "B. Sales" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "==============================" << std::endl;

        std::cout << "\nPLEASE ENTER YOUR CHOICE: ";
        std::cin >> action;

        switch (action)
        {
        case 'A':
        case'a':
            std::cout << "\nNavigating to Cashier..." << std::endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            Book::sellBook();
            break;
        case 'B':
        case'b':
            std::cout << "\nNavigating to Sales..." << std::endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            system("cls");
            //viewSales();
            break;
        case '0':
            std::cout << "Exiting..." << std::endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            merchantQuit = true;
            break;
        default:
            std::cout << "\nInvalid Input, please try again..." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            break;
        }
    } while (!merchantQuit);
}

void Book::push(string& bookTitle, string& bookAuthor, string& bookIsbn, double& bookPrice, int& bookQuantity)
{
    NODE* newNode = new NODE();
    newNode->title = bookTitle;
    newNode->author = bookAuthor;
    newNode->ISBN = bookIsbn;
    newNode->price = bookPrice;
    newNode->quantity = bookQuantity;
    newNode->next = top;
    top = newNode;

    numItem++;
}

void Book::pop()
{
    if (!empty())
    {
        NODE* temp = top;
        top = top->next;
        delete temp;
        --numItem;
    }
    else
    {
        std::cout << "There is no any book in the adding list..." << std::endl;
    }
}

void Book::searchBook()
{
    system("cls");
    NODE* pCurr = top;
    std::string searchTitle;
    std::cout << "Enter the title of the book to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // To clear the newline character from the buffer
    std::getline(std::cin, searchTitle);
    searchTitle = trim(searchTitle);
    std::string searchTitleLower = toLowerCase(searchTitle); //toLowerCase for case insensitive

    bool found = false;
    std::cout << "+------------------------------+--------------------+---------------+------------+----------+" << std::endl;
    std::cout << "| " << std::setw(28) << std::left << "Title"
        << " | " << std::setw(18) << std::left << "Author"
        << " | " << std::setw(13) << std::left << "ISBN"
        << " | " << std::setw(10) << std::left << "Price (RM)"
        << " | " << std::setw(8) << std::left << "Quantity"
        << " |" << std::endl;
    std::cout << "+------------------------------+--------------------+---------------+------------+----------+" << std::endl;

    while (pCurr) {
        std::string storedTitleLower = toLowerCase(trim(pCurr->title));

        // Check if the searchTitleLower is a prefix of storedTitleLower
        if (storedTitleLower.find(searchTitleLower) == 0) {
            found = true;
            std::cout << "| " << std::setw(28) << std::left << pCurr->title
                << " | " << std::setw(18) << std::left << pCurr->author
                << " | " << std::setw(13) << std::left << pCurr->ISBN
                << " | " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << pCurr->price
                << " | " << std::setw(8) << std::left << pCurr->quantity
                << " |" << std::endl;
            std::cout << "+------------------------------+--------------------+---------------+------------+----------+" << std::endl;
            if (!found) {
                std::cout << "Books found:" << std::endl;
                std::cout << "===========================" << std::endl;
            }
        }
        pCurr = pCurr->next;
    }
    if (!found) {
        std::cout << "No books found with the given title prefix." << std::endl;
    }
}

void Book::sellBook() {
    system("cls");

    NODE* pCurr = top;
    if (pCurr == nullptr) {
        std::cout << "The inventory is empty." << std::endl;
        _getch();
        return;
    }


    string searchTitle;
    std::cout << "Enter the title of the book to sell: ";

    // Clear the input buffer before reading
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Get the entire line of input from the user
    getline(cin, searchTitle);

    // Trim leading and trailing whitespace
    searchTitle = trim(searchTitle);

    // Convert to lowercase for case-insensitive comparison
    string searchTitleLower = toLowerCase(searchTitle);

    while (pCurr) {
        // Trim and convert stored title to lowercase for case-insensitive comparison
        string storedTitleLower = toLowerCase(trim(pCurr->title));

        // Check if the storedTitle matches the searchTitle
        if (storedTitleLower == searchTitleLower) {
            std::cout << "Book found:" << std::endl;
            std::cout << "Title: " << pCurr->title << std::endl;
            std::cout << "Author: " << pCurr->author << std::endl;
            std::cout << "ISBN: " << pCurr->ISBN << std::endl;
            std::cout << "Price: RM" << fixed << setprecision(2) << pCurr->price << std::endl;
            std::cout << "Quantity: " << pCurr->quantity << std::endl;

            char confirm;
            std::cout << "Do you want to sell this book? (Y/N): ";
            std::cin >> confirm;

            if (confirm == 'Y' || confirm == 'y') {
                int sellQuantity;
                std::cout << "Enter quantity to sell: ";
                std::cin >> sellQuantity;

                if (sellQuantity > pCurr->quantity) {
                    std::cout << "Not enough stock available." << std::endl;
                    std::cout << "\nPress any key back to the page." << std::endl;
                    _getch;
                    return;
                }

                pCurr->quantity -= sellQuantity;
                std::cout << "Book sold!" << std::endl;

                // Display receipt
                std::cout << "Receipt:" << std::endl;
                std::cout << "===========================" << std::endl;
                std::cout << "Title: " << pCurr->title << std::endl;
                std::cout << "Author: " << pCurr->author << std::endl;
                std::cout << "ISBN: " << pCurr->ISBN << std::endl;
                std::cout << "Price: RM" << fixed << setprecision(2) << pCurr->price << std::endl;
                std::cout << "Quantity Sold: " << sellQuantity << std::endl;
                std::cout << "Total: RM" << fixed << setprecision(2) << pCurr->price * sellQuantity << std::endl;
                std::cout << "===========================" << std::endl;

                std::cout << "\n\nPress any key back to the page." << std::endl;
                _getch;
                return;
            }
            else
            {
                std::cout << "Sale canceled..." << std::endl;
                std::this_thread::sleep_for(chrono::milliseconds(500));
                return;
            }
        }
        pCurr = pCurr->next;

    }

    std::cout << "Book not found." << std::endl;
}

string Book::toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

string Book::trim(const string& str) 
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void Book::update() 
{
    system("cls");
    Book::displayBookTable();
    std::cout << "\n\nPlease enter the title of the book you want to modify: ";
    std::string target;
    std::cin.ignore(); // To clear the newline character from the buffer
    std::getline(std::cin, target);

    NODE* pCurr = top;

    while (pCurr != nullptr && pCurr->title != target) {
        pCurr = pCurr->next;
    }

    if (pCurr == nullptr) {
        std::cout << "Book with title \"" << target << "\" not found.\n";
        return;
    }

    std::string newTitle, newAuthor, newISBN;
    double newPrice;
    int newQuantity;

    std::cout << "Enter new details for the book (leave blank to keep current value):\n";

    std::cout << "Title [" << pCurr->title << "]: ";
    std::getline(std::cin, newTitle);
    if (!newTitle.empty()) {
        pCurr->title = newTitle;
    }

    std::cout << "Author [" << pCurr->author << "]: ";
    std::getline(std::cin, newAuthor);
    if (!newAuthor.empty()) {
        pCurr->author = newAuthor;
    }

    std::cout << "ISBN [" << pCurr->ISBN << "]: ";
    std::getline(std::cin, newISBN);
    if (!newISBN.empty()) {
        pCurr->ISBN = newISBN;
    }

    std::cout << "Price [" << pCurr->price << "]: ";
    std::string priceInput;
    std::getline(std::cin, priceInput);
    if (!priceInput.empty()) {
        try {
            newPrice = std::stod(priceInput);
            pCurr->price = newPrice;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid price input, keeping current value.\n";
        }
    }

    std::cout << "Quantity [" << pCurr->quantity << "]: ";
    std::string quantityInput;
    std::getline(std::cin, quantityInput);
    if (!quantityInput.empty()) {
        try {
            newQuantity = std::stoi(quantityInput);
            pCurr->quantity = newQuantity;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid quantity input, keeping current value.\n";
        }
    }

    std::cout << "Book details updated successfully.\n";
}







