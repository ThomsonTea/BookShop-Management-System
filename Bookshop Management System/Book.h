#ifndef BOOK
#define BOOK

#include <string>
#include <iostream>


using namespace std;

class Book
{
public:
    Book();
    ~Book();
    void searchBook();
    void push(string&, string&, string&, double&, int&);
    void pop();
    void addBook();
    void deleteBook();
    //void modifyBook();
    bool empty();
    int getNumberOfBooks();
    void displayInventory();
    void ascendingTitleInsertionSort();
    void descendingTitleInsertionSort();
    void ascendingAuthorInsertionSort();
    void descendingAuthorInsertionSort();
    void insertionSort();
    void updateBook();

private:
    class NODE 
    {
     public:
            string title;
            string author;
            string ISBN;
            double price;
            int quantity;
            
            NODE* next;
    };

    NODE* pHead;
    NODE* top;
    int numItem;
};

#endif