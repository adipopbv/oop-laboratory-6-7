#include <iostream>
#include <vector>

#include "business/services.h"
#include "domain/entities.h"
#include "interface/clients.h"

auto main() -> int
{
	std::vector<Book> booksRepo; // the books repository
	LibraryService libraryService = LibraryService(booksRepo); // the library service
	LibraryClient libraryClient = LibraryClient(libraryService); // the library client

	libraryClient.RunApplication(); // application loop

	return 0;
}
