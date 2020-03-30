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

void LibraryService::ModifyBookInRepo(std::string titleSearch, std::string authorSearch, std::string title, std::string author, std::string genre, int releaseYear)
{
	for (int i = 0; i < (int)this->booksRepo.size(); i++) // searching for the book with the given title and author
	{
		if (this->booksRepo[i].getTitle() == titleSearch && this->booksRepo[i].getAuthor() == authorSearch) // change book if found
		{
			Book newBook = this->booksRepo[i]; // copying the book to be modified

			// changing wanted values
			if (title != "")
				newBook.setTitle(title);
			if (author != "")
				newBook.setAuthor(author);
			if (genre != "")
				newBook.setGenre(genre);
			if (releaseYear != -1)
				newBook.setReleaseYear(releaseYear);

			this->booksRepo.erase(this->booksRepo.begin() + i); // remove the old one
			this->booksRepo.insert(this->booksRepo.begin() + i, newBook); // insert the new one

			return;
		}
	}
	throw (std::string)"book not found in repo"; // exception if book not found
}

void LibraryService::DeleteBookFromRepo(std::string titleSearch, std::string authorSearch)
{
	for (int i = 0; i < (int)this->booksRepo.size(); i++) // searching for the book with the given title and author
	{
		if (this->booksRepo[i].getTitle() == titleSearch && this->booksRepo[i].getAuthor() == authorSearch) // change book if found
		{
			this->booksRepo.erase(this->booksRepo.begin() + i); // remove the old one
			return;
		}
	}
	throw (std::string)"book not found in repo"; // exception if book not found
}
