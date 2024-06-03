#include <iostream>
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
