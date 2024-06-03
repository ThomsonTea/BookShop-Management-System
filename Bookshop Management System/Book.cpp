#include <iostream>
#include <thread>
#include <chrono>
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

void Book::push(string& bookTitle, string & bookAuthor, string & bookIsbn, double &bookPrice, int &bookQuantity)
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

void Book::addBook()
{   
    string newBookTitle;
    string newBookAuthor;
    string newBookIsbn;
    double newBookPrice;
    int newBookQuantity;
    bool endinsert = false;

    do 
    {
        int numberNewBooks = 0;
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

        std::cout << "The number of the books to be added is " << numberNewBooks << std::endl;
        
        std::cout << "=============================================" << std::endl;
        std::cout << "Please choose your next action" << std::endl;
        std::cout << "\n1. Add Next";
        std::cout << "\n2. Undo";
        std::cout << "\n0. Finish";
        
        std::cin >> addingAction;

        switch (addingAction)
        {
        case '1':
            std::cout << "Preparing for the next books..." << std::endl;
            break;
        case '2':
            if (numberNewBooks != 0)
            {
                //pop()
            }
            else
            {
                std::cout << "There doesn't have any books in the lists" << std::endl;
            }
            break;
        case '0':
            std::cout << "Inserting the books into inventory..." << std::endl;
            std::cout << "Insert completed!" << std::endl;

            endinsert = true;
            break;
        default:
            std::cout << "Invalid input, please try again..." << std::endl;
            break;
        }


    } while (!endinsert);
}

bool Book::empty()
{
    return (numItem == 0);
}