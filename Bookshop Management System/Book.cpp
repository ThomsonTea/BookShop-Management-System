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
    pHead = nullptr;
    pCurr = nullptr;
    top = NULL;
    numItem = 0;
}

Book::~Book()
{
}

int Book::getNumberOfBooks()
{
    return numItem;
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
    if (empty())
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

string trim(const string& str) 
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


// Function to convert string to lowercase
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Book::searchBook() 
{
    NODE* pCurr = top;
    std::string searchTitle;
    std::cout << "Enter the title of the book to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // To clear the newline character from the buffer
    std::getline(std::cin, searchTitle);
    searchTitle = trim(searchTitle);
    std::string searchTitleLower = toLowerCase(searchTitle); //toLowerCase for case insensitive

    bool found = false;
    std::cout << "+------------------------------+--------------------+---------------+----------+----------+" << std::endl;
    std::cout << "| " << std::setw(28) << std::left << "Title"
        << " | " << std::setw(18) << std::left << "Author"
        << " | " << std::setw(13) << std::left << "ISBN"
        << " | " << std::setw(10) << std::left << "Price"
        << " | " << std::setw(10) << std::left << "Quantity"
        << " |" << std::endl;
    std::cout << "+------------------------------+--------------------+---------------+----------+----------+" << std::endl;

    while (pCurr) {
        std::string storedTitleLower = toLowerCase(trim(pCurr->title));

        // Check if the searchTitleLower is a prefix of storedTitleLower
        if (storedTitleLower.find(searchTitleLower) == 0) {
            if (!found) {
                std::cout << "Books found:" << std::endl;
                std::cout << "===========================" << std::endl;
            }
            found = true;
            std::cout << "| " << std::setw(28) << std::left << pCurr->title
                << " | " << std::setw(18) << std::left << pCurr->author
                << " | " << std::setw(13) << std::left << pCurr->ISBN
                << " | " << std::setw(10) << std::left << "RM " << std::fixed << std::setprecision(2) << pCurr->price
                << " | " << std::setw(10) << std::left << pCurr->quantity
                << " |" << std::endl;
            std::cout << "+------------------------------+--------------------+---------------+----------+----------+" << std::endl;

        }
        pCurr = pCurr->next;
    }
    if (!found) {
        std::cout << "No books found with the given title prefix." << std::endl;
    }
}


bool Book::empty()
{
    return (numItem == 0);
}

void Book::addBook()
{
    string newBookTitle;
    string newBookAuthor;
    string newBookIsbn;
    double newBookPrice;
    int newBookQuantity;
    bool endinsert = false;

    int numberNewBooks = 0;
    do
    {
        system("cls");
        char addingAction;
        std::cout << "==========================================" << std::endl;
        std::cout << "Please key in the informations of new Books" << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cin.ignore(); // Clear the input buffer
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
        std::cout << "\n0. Comfirm" << std::endl;

        std::cout << "Please choose your next action: ";

        std::cin >> addingAction;

        switch (addingAction)
        {
        case '1':
            std::cout << "\nPreparing for the next books..." << std::endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            break;
        case '2':
            if (numberNewBooks != 0)
            {
                Book::pop();
                --numberNewBooks;
            }
            else
            {
                std::cout << "\nThere doesn't have any books in the lists" << std::endl;
                std::this_thread::sleep_for(chrono::seconds(1));
            }
            continue;
        case '0':
            std::cout << "\nInserting the books into inventory..." << std::endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            std::cout << "Insert completed!" << std::endl;


            endinsert = true;
            break;
        default:
            std::cout << "\nInvalid input, please try again..." << std::endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            break;

        }
    } while (!endinsert);
}

void Book::displayInventory()
{
    system("cls");
    NODE* pCurr = top;
    if (pCurr == nullptr) {
        std::cout << "The inventory is empty." << std::endl;
        return;
    }

    std::cout << "+-----+------------------------------+--------------------+---------------+----------+----------+" << std::endl;
    std::cout << "| " << std::setw(3) << "No"
        << " | " << std::setw(28) << "Title"
        << " | " << std::setw(18) << "Author"
        << " | " << std::setw(13) << "ISBN"
        << " | " << std::setw(8) << "Price"
        << " | " << std::setw(8) << "Quantity"
        << " |" << std::endl;
    std::cout << "+-----+------------------------------+--------------------+---------------+----------+----------+" << std::endl;

    int bookNumber = 1;

    while (pCurr != nullptr) {
        std::cout << "| " << std::setw(3) << bookNumber
            << " | " << std::setw(28) << pCurr->title
            << " | " << std::setw(18) << pCurr->author
            << " | " << std::setw(13) << pCurr->ISBN
            << " | " << std::setw(8) << pCurr->price
            << " | " << std::setw(8) << pCurr->quantity
            << " |" << std::endl;
        std::cout << "+-----+------------------------------+--------------------+---------------+----------+----------+" << std::endl;

        pCurr = pCurr->next;
        bookNumber++;
    }

    
    std::cout << "\n\nPress any key to quit: ";
    _getch();
}

void Book::ascending_title_insertionSort()
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

void Book::descending_title_insertionSort()
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

void Book::ascending_author_insertionSort()
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

void Book::descending_author_insertionSort()
{
    if (!top || !top->next) return; // No need to sort if list is empty or has only one element

    NODE* sorted = nullptr; // Start with an empty sorted list

    while (top) {
        NODE* pCurr = top;
        top = top->next;

        if (!sorted || sorted->author < pCurr->author) {
            // Insert at the beginning of the sorted list
            pCurr->next = sorted;
            sorted = pCurr;
        }
        else {
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


