#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include "Book.h"
#include "limits"
#include "algorithm"
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
string trim(const string& str) {
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
void Book::searchBook() {
    NODE* pCurr = top;
    string searchTitle;
    cout << "Enter the title of the book to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // To clear the newline character from the buffer
    getline(cin, searchTitle);
    searchTitle = trim(searchTitle);
    string searchTitleLower = toLowerCase(searchTitle);

    bool found = false;
    while (pCurr) {
        string storedTitleLower = toLowerCase(trim(pCurr->title));

        // Check if the searchTitleLower is a prefix of storedTitleLower
        if (storedTitleLower.find(searchTitleLower) == 0) {
            if (!found) {
                cout << "Books found:" << endl;
                cout << "===========================" << endl;
            }
            found = true;
            cout << "Title: " << pCurr->title << endl;
            cout << "Author: " << pCurr->author << endl;
            cout << "ISBN: " << pCurr->ISBN << endl;
            cout << "Price: $" << fixed << setprecision(2) << pCurr->price << endl;
            cout << "Quantity: " << pCurr->quantity << endl;
            cout << "---------------------------" << endl;
       
        }
        pCurr = pCurr->next;
    }
    if (!found) {
        cout << "No books found with the given title prefix." << endl;
}
}

/*void Book::printOutFunction()
{
NODE* pCurr = top;
while (pCurr) {
   if(pCurr == top){
    std::cout << "The title is " << pCurr->title << std::endl;
    std::cout << "\nThe author is " << pCurr->author << std::endl;
    std::cout << "\nThe ISBN is " << pCurr->isbn << std::endl;
    std::cout << "\nThe price is " << pCurr->price << std::endl;
    std::cout << "\nThe quantity is " << pCurr->quantity << std::endl;
    }
    pCurr = pCurr->next;
    }
}*/

void Book::insertionSort()
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

bool Book::empty()
{
    return (numItem == 0);
}