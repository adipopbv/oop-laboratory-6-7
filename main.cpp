#include <iostream>
#include <vector>

#include "domain/entities.h"
#include "business/services.h"
#include "interface/clients.h"

int main()
{
	std::vector<Book> booksRepo; // the books repository
	LibraryService libraryService = LibraryService(booksRepo);
	LibraryClient libraryClient = LibraryClient(libraryService);

	libraryClient.RunApplication();

	return 0;
}
