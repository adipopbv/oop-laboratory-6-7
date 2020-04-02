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
	if (this->getBooksRepo().Empty()) // throw exception if empty repo
		throw EmptyRepoError("no book in repository");
	// returning all books
	return this->getBooksRepo();
}
Repo<Book> LibraryService::GetBooks() const 
{
	if (this->getBooksRepo().Empty()) // throw exception if empty repo
		throw EmptyRepoError("no book in repository");
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
	// validating search fields
	if (titleSearch.empty() || authorSearch.empty())
		throw SearchFieldsError("nothing to search by");

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
	tempRepo.Insert(newBook, oldBookIndex); // insert the new one
	tempRepo.Erase(oldBookIndex + 1); // remove the old one
	// set the new state
	this->setBooksRepo(tempRepo);
}

void LibraryService::DeleteBookFromRepo(const std::string &titleSearch, const std::string &authorSearch)
{
	// validating search fields
	if (titleSearch.empty() || authorSearch.empty())
		throw SearchFieldsError("nothing to search by");

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

Book LibraryService::SearchBook(const std::string &titleSearch, const std::string &authorSearch, const std::string &genreSearch, const int &releaseYearSearch)
{
	if (titleSearch.empty() && authorSearch.empty() && genreSearch.empty() && releaseYearSearch == -1)
		throw SearchFieldsError("\nno search fields entered"); // throw exception if no searche fields entered

	Book searchedBook = this->getBooksRepo().GetElement(
		[ &titleSearch, &authorSearch, &genreSearch, &releaseYearSearch ]
		( Book searchedBook ) 
		{ 
			bool found = true;
			if (!titleSearch.empty()) // search by title
				found = found && searchedBook.getTitle() == titleSearch;
			if (!authorSearch.empty()) // search by author
				found = found && searchedBook.getAuthor() == authorSearch;
			if (!genreSearch.empty()) // search by genre
				found = found && searchedBook.getGenre() == genreSearch;
			if (releaseYearSearch != -1) // search by release year
				found = found && searchedBook.getReleaseYear() == releaseYearSearch;
			return found;
		}
	);
	return searchedBook;
}
