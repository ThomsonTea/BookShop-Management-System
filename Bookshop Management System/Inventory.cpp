#include <iostream>
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
		std::cout << "A. Insert Books" << std::endl;
		std::cout << "B. Edit Books" << std::endl;
		std::cout << "C. Delete Books" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "==============================" << std::endl;

		std::cout << "\nPLEASE ENTER YOUR CHOICE: ";
		std::cin >> action;

		switch (action)
		{
			case 'A':
			case 'a':
				std::cout << "insert" << std::endl;
				system("cls");
				book.addBook();
				break;
			case 'B':
			case 'b':
				std::cout << "Edit" << std::endl;
				system("cls");
				//modifyBooks();
				break;
			case 'C':
			case 'c':
				std::cout << "delete" << std::endl;
				system("cls");
				//deleteBooks();
				break;
			case '0':
				inventoryQuit = true;
				system("cls");
				break;
			default:
				std::cout << "\nInvalid Input, please try again..." << std::endl;
				break;
		}
	} while (!inventoryQuit);

}
