#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "Inventory.h"
#include "Merchant.h"
using namespace std;
//asdsadasdadsa
//asdasdasdasdas
int main()
{
    bool quit = false;

    do
    {
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
            cout << "Navigating to Merchant" << endl;
            system("cls");
            merchantMainPage();
        }
        else if (site == 'B' || site == 'b')
        {
            cout << "Navigating to Inventory" << endl;
            system("cls");
            inventoryMainPage();
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
                cout << "Returning ..." << endl;
                system("cls");
            }
        }
        else
        {
            cout << "\nInvalid Input, please try again..." << endl;
            system("cls");
        }
    } while (!quit);

    return 0;
}