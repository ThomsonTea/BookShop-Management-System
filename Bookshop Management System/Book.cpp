#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include "Book.h"
#include "limits"

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


void Book::searchBook() {
    NODE* pCurr = pHead;
    string searchTitle;
    cout << "Enter the title of the book to search: ";
    cin >> searchTitle;
    //cin.ignore();    // To clear the newline character from the buffer
    getline(cin, searchTitle);

    while (pCurr) {
        if (pCurr->title == searchTitle) {
            cout << "Book found:" << endl;
            cout << "Title: " << pCurr->title << endl;
            cout << "Author: " << pCurr->author << endl;
            cout << "ISBN: " << pCurr->ISBN << endl;
            cout << "Price: $" << pCurr->price << endl;
            cout << "Quantity: " << pCurr->quantity << endl;
            cout << "---------------------------" << endl;
            return;
        }
        pCurr = pCurr->next;
    }
    //cout << "Book not found." << endl;
}

/*void Book::printOutFunction()
{
   std::cout << "The title is " << bookTitle << std::endl;
    std::cout << "\nThe author is " << bookAuthor << std::endl;
    std::cout << "\nThe ISBN is " << bookIsbn << std::endl;
    std::cout << "\nThe price is " << bookPrice << std::endl;
    std::cout << "\nThe quantity is " << bookQuantity << std::endl;
}*/

bool Book::empty()
{
    return (numItem == 0);
}