#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <thread>
#include <conio.h>
#include "Book.h"
using namespace std;

int main()
{
    bool quit = false;
    Book book;

    do
    {
        system("cls");

        char site;
        cout << "=========================================" << endl;
        cout << "       BOOK SHOP MANAGEMENT SYSTEM       " << endl;
        cout << "=========================================" << endl;
        cout << "A. MERCHANT" << endl;
        cout << "B. INVENTORY" << endl;
        cout << "0. EXIT" << endl;
        cout << "=========================================" << endl;

        cout << "\nPLEASE CHOOSE YOUR SITE: ";
        cin >> site;

        if (site == 'A' || site == 'a')
        {
            cout << "\nNavigating to Merchant..." << endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            system("cls");
            book.merchantMainPage();
        }
        else if (site == 'B' || site == 'b')
        {
            cout << "\nNavigating to Inventory..." << endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            system("cls");
            book.inventoryMainPage();
        }
        else if (site == '0')
        {
            string exitpass;
            system("cls");
            cout << "ARE YOU SURE?\n" << "PLEASE TYPE \"YES\" TO EXIT\n";
            cin >> exitpass;

            if (exitpass == "YES")
            {
                quit = true;
            }
            else
            {
                cout << "\nExiting..." << endl;
                std::this_thread::sleep_for(chrono::seconds(1));
                system("cls");
            }
        }
        else
        {
            cout << "\nInvalid Input, please try again..." << endl;
            std::this_thread::sleep_for(chrono::milliseconds(500));
            system("cls");
        }
    } while (!quit);

    return 0;
}