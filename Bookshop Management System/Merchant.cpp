#include <iostream>
#include <chrono>
#include <thread>

#include "Merchant.h"
#include "Book.h"
//ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
//ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
//ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
void merchantMainPage()
{
	bool merchantQuit = false;

	do {
		system("cls");
		char action;
		std::cout << "==============================" << std::endl;
		std::cout << "          MERCHANT            " << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << "A. Cashier" << std::endl;
		std::cout << "B. Sales" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "==============================" << std::endl;

		std::cout << "\nPLEASE ENTER YOUR CHOICE: ";
		std::cin >> action;

		switch (action)
		{
		case 'A':
		case'a':
			std::cout << "Cashier" << std::endl;
			system("cls");
			//sellBook();
			break;
		case 'B':
		case'b':
			std::cout << "modify" << std::endl;
			system("cls");
			//viewSales();
			break;
		case '0':
			merchantQuit = true;
			system("cls");
			break;
		default:
			system("cls");
			std::cout << "\nInvalid Input, please try again..." << std::endl;
			this_thread::sleep_for(chrono::milliseconds(500));
			break;
		}
	} while (!merchantQuit);

}

/*void::viewsales()
{

}*/