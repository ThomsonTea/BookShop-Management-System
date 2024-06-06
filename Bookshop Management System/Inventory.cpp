#include <iostream>//hehe this is inventory
#include <chrono>
#include <thread>

#include "Inventory.h"
#include "Book.h"

void inventoryMainPage()
{
    bool inventoryQuit = false;
    Book book;
    do {
        char action;
        std::cout << "==============================" << std::endl;
        std::cout << "          INVENTORY           " << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "A. Show Books" << std::endl;
        std::cout << "B. Insert Books" << std::endl;
        std::cout << "C. Edit Books" << std::endl;
        std::cout << "D. Delete Books" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "==============================" << std::endl;

        std::cout << "\nPLEASE ENTER YOUR CHOICE: ";
        std::cin >> action;

        switch (action)
        {
        case 'A':
        case 'a':
            std::cout << "Show" << std::endl;
            
            system("cls");
            book.displayInventory();

            break;
        case 'B':
        case 'b':
            std::cout << "Insert" << std::endl;
            book.addBook();
            break;
        case 'C':
        case 'c':
            std::cout << "Edit" << std::endl;
            system("cls");
            //editBooks();
            break;
        case 'D':
        case 'd':
            std::cout << "Delete" << std::endl;
            system("cls");
            //deleteBooks();
            break;
        case '0':
            inventoryQuit = true;
            system("cls");
            break;
        default:
            std::cout << "\nInvalid Input, please try again..." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            break;
        }
    } while (!inventoryQuit);

}

//display inventory
void Book::displayInventory()
{
    NODE* current = top;
    if (current == nullptr) {
        std::cout << "The inventory is empty." << std::endl;
        return;

    }
    std::cout << "Book Inventory:" << endl;
    std::cout << "=========================" << endl;
    int bookNumber = 1;
    while (current != nullptr) {
        std::cout << "Book " << bookNumber << ":" << std::endl;
        std::cout << "Title: " << current->title << std::endl;
        std::cout << "Author: " << current->author << std::endl;
        std::cout << "ISBN: " << current->ISBN << std::endl;
        std::cout << "Price: $" << current->price << std::endl;
        std::cout << "Quantity: " << current->quantity << std::endl;
        std::cout << "---------------------------" << std::endl;
        current = current->next;
        bookNumber++;
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

            endinsert = true;
            break;
        default:
            std::cout << "\nInvalid input, please try again..." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            break;
        }


    } while (!endinsert);

    
}
