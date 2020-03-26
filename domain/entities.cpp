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
	this->setTitle(NULL);
	this->setAuthor(NULL);
	this->setGenre(NULL);
	this->setReleaseYear(0);
}
