#ifndef BOOK
#define BOOK

#include <string>
#include <iostream>
#include <fstream> // Added for file operations
using namespace std;

class Book
{
public:
    Book();
    ~Book();
    void searchBook();
    void push(string&, string&, string&, double&, int&);
    void addBook();
    void deleteBook();
    void modifyBook();
    bool empty();
    int getNumberOfBooks();
    void printout(const string& message, const string& level = "INFO"); // declaration of the printout function
    void displayBooks(); // Declaration of the displayBooks function

private:
    class NODE {
    public:
        string title;
        string author;
        string ISBN;
        double price;
        int quantity;
        NODE* next;
    };

    NODE* pHead;
    NODE* pCurr;
    NODE* top;
    int numItem;
    ofstream logFile; // Log file stream
};

#endif