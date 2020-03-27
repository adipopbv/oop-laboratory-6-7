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

std::vector<Book> LibraryService::GetBooks(std::string title, int releaseYear)
{
	return std::vector<Book>();
}
std::vector<Book> LibraryService::GetBooks(std::string title)
{
	return std::vector<Book>();
}
std::vector<Book> LibraryService::GetBooks(int releaseYear)
{
	return std::vector<Book>();
}
std::vector<Book> LibraryService::GetBooks()
{
	// returning all books
	return this->getBooksRepo();
}

void LibraryService::AddBookToRepo(std::string title, std::string author, std::string genre, int releaseYear)
{
	Book book = Book(title, author, genre, releaseYear);
	this->booksRepo.push_back(book); // adding a new book to the end of the repo
}
