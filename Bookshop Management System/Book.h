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
    void addBook();
    void ascendingTitleInsertionSort();
    void ascendingAuthorInsertionSort();
    void deleteBook();
    void descendingAuthorInsertionSort();
    void descendingTitleInsertionSort();
    void displayBookTable();
    void displayInventory();
    bool empty();
    int getNumberOfBooks();
    void inventoryMainPage();
    void merchantMainPage();
    void searchBook();
    void push(string&, string&, string&, double&, int&);
    void pop();
    void sellBook();
    string toLowerCase(const string& str);
    string trim(const string& str);
    void update();

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