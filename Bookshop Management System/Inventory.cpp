#include <iostream>//hehe this is inventory
#include <chrono>
#include <thread>
#include <iomanip>

#include "Inventory.h"
#include "Book.h"


void inventoryMainPage()
{
    Book book;
    bool inventoryQuit = false;
    do {
        system("cls");

        char action;

        std::cout << "==============================" << std::endl;
        std::cout << "          INVENTORY           " << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "A. Show Books" << std::endl;
        std::cout << "B. Insert Books" << std::endl;
        std::cout << "C. Edit Books" << std::endl;
        std::cout << "D. Delete Books" << std::endl;
        std::cout << "E. Search for Books" << std::endl;
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
            break;
        case 'E':
        case 'e':
            std::cout << "Search" << std::endl;
            system("cls");
            {
                bool searchAgain = false;
                do {
                    book.searchBook();
                    char searchOption;
                    cout << "Do you want to search for another book? (Y/N): ";
                    cin >> searchOption;
                    while (searchOption != 'Y' && searchOption != 'y' && searchOption != 'N' && searchOption != 'n') {
                        cout << "Invalid input. Please enter 'Y' or 'N': ";
                        cin >> searchOption;
                    }
                    searchAgain = (searchOption == 'Y' || searchOption == 'y');
                } while (searchAgain);
            }
            break;
        case '0':
            inventoryQuit = true;
            system("cls");
            break;
        default:
            std::cout << "\nInvalid Input, please try again..." << std::endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            break;
        }
    } while (!inventoryQuit);
}

