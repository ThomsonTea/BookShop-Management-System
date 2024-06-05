// Book.cpp
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

#include "Book.h"

Book::Book()
{
    pHead = nullptr;
    pCurr = nullptr;
    top = NULL;
    numItem = 0;
    logFile.open("app.log", ios::app); // Open log file in append mode
}

Book::~Book()
{
    if (logFile.is_open()) {
        logFile.close();
    }
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
    printout("Book added: " + bookTitle);
}

bool Book::empty()
{
    return (numItem == 0);
}

void Book::printout(const string& message, const string& level) // print out function 
{
    string timestamp = to_string(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
    string logMessage = "[" + timestamp + "] [" + level + "] " + message;

    // Print to console
    cout << logMessage << endl;

    // Write to log file
    if (logFile.is_open()) {
        logFile << logMessage << endl;
    }
}

void Book::displayBooks() //displaybooks function 
{
    if (empty()) {
        cout << "No books in inventory." << endl;
        return;
    }

    NODE* current = top;
    while (current != nullptr) {
        cout << "Title: " << current->title << endl;
        cout << "Author: " << current->author << endl;
        cout << "ISBN: " << current->ISBN << endl;
        cout << "Price: " << current->price << endl;
        cout << "Quantity: " << current->quantity << endl;
        cout << "-----------------------------------------" << endl;
        current = current->next;
    }
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
        std::cout << "Please key in the infomations of new Books" << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "\nBookName: ";
        std::cin >> newBookTitle;
        std::cout << "\nAuthor: ";
        std::cin >> newBookAuthor;
        std::cout << "\nISBN: ";
        std::cin >> newBookIsbn;
        std::cout << "\nPrice: ";
        std::cin >> newBookPrice;
        std::cout << "\nQuantity: ";
        std::cin >> newBookQuantity;

        std::cout << "===========================================" << std::endl;

        push(newBookTitle, newBookAuthor, newBookIsbn, newBookPrice, newBookQuantity);
        numberNewBooks++;

        printout("Book added: " + newBookTitle);

        std::cout << "The number of the books to be added is " << numberNewBooks << std::endl;

        std::cout << "=============================================" << std::endl;
        std::cout << "\n\n1. Add Next";
        std::cout << "\n2. Undo";
        std::cout << "\n0. Finish" << std::endl;

        std::cout << "Please choose your next action: ";

        std::cin >> addingAction;

        switch (addingAction)
        {
        case '1':
            std::cout << "\nPreparing for the next books..." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            break;
        case '2':
            if (numberNewBooks != 0)
            {
                //pop()
            }
            else
            {
                std::cout << "\nThere doesn't have any books in the lists" << std::endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            break;
        case '0':
            std::cout << "\nInserting the books into inventory..." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            std::cout << "Insert completed!" << std::endl;
            printout("Books inserted into inventory");

            endinsert = true;
            break;
        default:
            std::cout << "\nInvalid input, please try again..." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            break;
        }


    } while (!endinsert);
}
