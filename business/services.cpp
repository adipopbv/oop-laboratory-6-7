#include "./services.h"

LibraryService::LibraryService(std::vector<Book> booksRepo)
{
	// setting fields of LibraryService instance to parameter values
	this->setBooksRepo(booksRepo);
}

LibraryService::~LibraryService()
{
	// setting fields of LibraryService instance to default values
	this->setBooksRepo(std::vector<Book>());
}
