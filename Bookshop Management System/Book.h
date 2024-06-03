#ifndef BOOK
#define BOOK

#include <string>
#include <iostream>

class Book
{
public:
    Book();
    ~Book();
    void searchBook();
    void addBook();
    void deleteBook();
    void modifyBook();

private:
    class NODE {
    public:
        std::string title;
        std::string author;
        int price;
        std::string ISBN[14];

        NODE* link;
    };

    NODE* pHead;
    NODE* pCurr;
    int numItem;
};

#endif
