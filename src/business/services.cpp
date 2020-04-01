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
	for (int i = 0; i < static_cast<int>(this->booksRepo.Size()); i++) // searching for the book with the given title and author
	{
		if (this->booksRepo[i].getTitle() == titleSearch && this->booksRepo[i].getAuthor() == authorSearch) // change book if found
		{
			Book newBook = this->booksRepo[i]; // copying the book to be modified

			// changing wanted values
			if (!title.empty())
			{ newBook.setTitle(title); }
			if (!author.empty())
			{ newBook.setAuthor(author); }
			if (!genre.empty())
			{ newBook.setGenre(genre); }
			if (releaseYear != -1)
			{ newBook.setReleaseYear(releaseYear); }

			this->booksRepo.Erase(i); // remove the old one
			this->booksRepo.Insert(newBook, i); // insert the new one

			return;
		}
	}
	throw std::string("book not found in repo"); // exception if book not found
}

void LibraryService::DeleteBookFromRepo(const std::string &titleSearch, const std::string &authorSearch)
{
	for (int i = 0; i < static_cast<int>(this->booksRepo.Size()); i++) // searching for the book with the given title and author
	{
		if (this->booksRepo[i].getTitle() == titleSearch && this->booksRepo[i].getAuthor() == authorSearch) // change book if found
		{
			this->booksRepo.Erase(i); // remove the old one
			return;
		}
	}
	throw std::string("book not found in repo"); // exception if book not found
}
