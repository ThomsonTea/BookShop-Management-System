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
    //void deleteBook();
    //void modifyBook();
    bool empty();
    int getNumberOfBooks();
    //void printOutFunction();
    void displayInventory();
    void ascending_title_insertionSort();
    void descending_title_insertionSort();
    void ascending_author_insertionSort();
    void descending_author_insertionSort();


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
};

#endif