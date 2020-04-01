#include <iostream>

#include "business/services.h"
#include "domain/entities.h"
#include "infrastructure/repos.h"
#include "interface/clients.h"

auto main() -> int
{
	Repo<Book> booksRepo = Repo<Book>(); // the books repository
	LibraryService libraryService = LibraryService(booksRepo); // the library service
	LibraryClient libraryClient = LibraryClient(libraryService); // the library client

	libraryClient.RunApplication(); // application loop

	return 0;
}
