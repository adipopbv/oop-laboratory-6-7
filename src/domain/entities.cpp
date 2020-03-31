#include "./entities.h"

Book::Book(std::string title, std::string author, std::string genre, int releaseYear)
{
	// setting fields of Book instance to parameter values
	this->setTitle(title);
	this->setAuthor(author);
	this->setGenre(genre);
	this->setReleaseYear(releaseYear);
}

Book::~Book()
{
	// setting fields of Book instance to default values
	this->setTitle("");
	this->setAuthor("");
	this->setGenre("");
	this->setReleaseYear(0);
}
