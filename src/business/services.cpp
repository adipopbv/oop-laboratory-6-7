#include "./services.h"

LibraryService::LibraryService(const Repo<Book> &booksRepo)
{
	// setting fields of LibraryService instance to parameter values
	this->setBooksRepo(booksRepo);
}

LibraryService::~LibraryService()
{
	// setting fields of LibraryService instance to default values
	this->setBooksRepo(Repo<Book>());
}

Repo<Book> LibraryService::GetBooks(const std::string &title, const int &releaseYear) const 
{
	// returning all books
	return this->getBooksRepo();
}
Repo<Book> LibraryService::GetBooks(const std::string &title) const 
{
	// returning all books
	return this->getBooksRepo();
}
Repo<Book> LibraryService::GetBooks(const int &releaseYear) const 
{
	// returning all books
	return this->getBooksRepo();
}
Repo<Book> LibraryService::GetBooks() const 
{
	// returning all books
	return this->getBooksRepo();
}

void LibraryService::AddBookToRepo(const std::string &title, const std::string &author, const std::string &genre, const int &releaseYear)
{
	Book book = Book(title, author, genre, releaseYear);
	this->booksRepo.Add(book); // adding a new book to the end of the repo
}

void LibraryService::ModifyBookInRepo(const std::string &titleSearch, const std::string &authorSearch, const std::string &title, const std::string &author, const std::string &genre, const int &releaseYear)
{
	// making a working copy of the repo
	Repo<Book> tempRepo = this->getBooksRepo();

	// getting the book to be modified's index
	int oldBookIndex = this->getBooksRepo().GetIndexOfElement(
		[ &titleSearch, &authorSearch ]
		( Book searchedBook ) 
		{ return searchedBook.getTitle() == titleSearch && searchedBook.getAuthor() == authorSearch; }
	);

	// making a new one with the wanted values changed
	Book newBook = tempRepo[oldBookIndex];
	if (!title.empty())
	{ newBook.setTitle(title); }
	if (!author.empty())
	{ newBook.setAuthor(author); }
	if (!genre.empty())
	{ newBook.setGenre(genre); }
	if (releaseYear != -1)
	{ newBook.setReleaseYear(releaseYear); }
	newBook.ValidateData(newBook.getTitle(), newBook.getAuthor(), newBook.getGenre(), newBook.getReleaseYear());

	// removing the old one and inserting the new one in place
	tempRepo.Erase(oldBookIndex); // remove the old one
	tempRepo.Insert(newBook, oldBookIndex); // insert the new one
	// set the new state
	this->setBooksRepo(tempRepo);
}

void LibraryService::DeleteBookFromRepo(const std::string &titleSearch, const std::string &authorSearch)
{
	// making a working copy of the repo
	Repo<Book> tempRepo = this->getBooksRepo();

	// getting the book to be modified's index
	int oldBookIndex = this->getBooksRepo().GetIndexOfElement(
		[ &titleSearch, &authorSearch ]
		( Book searchedBook ) 
		{ return searchedBook.getTitle() == titleSearch && searchedBook.getAuthor() == authorSearch; }
	);

	tempRepo.Erase(oldBookIndex); // removing the book
	// set the new state
	this->setBooksRepo(tempRepo);
}
