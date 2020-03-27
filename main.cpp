#include <iostream>
#include <vector>

#include "domain/entities.h"
#include "business/services.h"
#include "interface/clients.h"

int main()
{
	std::vector<Book> booksRepo; // the books repository
	LibraryService libraryService = LibraryService(booksRepo); // the library service
	LibraryClient libraryClient = LibraryClient(libraryService); // the library client

	libraryClient.RunApplication(); // application loop

	return 0;
}
