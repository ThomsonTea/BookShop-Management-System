#ifndef BOOK
#define BOOK

#include <string>

class BOOK
{
public:
	void searchBook();
	void addBook();
	void deleteBook();
	void modifyBook();

private:
	class NODE {
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

