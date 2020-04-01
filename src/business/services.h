#pragma once

#include <string>

#include "../domain/entities.h"
#include "../infrastructure/repos.h"

class LibraryService
{
	private:
		/// The books repository
		Repo<Book> booksRepo = Repo<Book>();

	public:
		/// Library service constructor
		LibraryService(const Repo<Book> &booksRepo = Repo<Book>());

		/// Library service destructor
		~LibraryService();

		/// Books repository getter
		Repo<Book> getBooksRepo() const { return this->booksRepo; }
		/// Books repository setter
		void setBooksRepo(Repo<Book> const &value) { this->booksRepo = value; }

		/**
		 * Gets books from the repo
		 *
		 * @param title Filter by title of the book
		 * @param releaseYear Filter by release year of the book
		 */
		Repo<Book> GetBooks(const std::string &title, const int &releaseYear) const;
		Repo<Book> GetBooks(const std::string &title) const;
		Repo<Book> GetBooks(const int &releaseYear) const;
		Repo<Book> GetBooks() const;

		/**
		 * Adds a book to the repo
		 *
		 * @param title The title of the book
		 * @param author The author of the book
		 * @param genre The genre of the book
		 * @param releaseYear The release year of the book
		 */
		void AddBookToRepo(const std::string &title = "", const std::string &author = "", const std::string &genre = "", const int &releaseYear = 0);

		/**
		 * Modifies a book from the repo, searching by title and author
		 *
		 * @param titleSearch The title to search by
		 * @param authorSearch The author to search by
		 * @param title The new title of the book
		 * @param author The new author of the book
		 * @param genre The new genre of the book
		 * @param releaseYear The new release year of the book
		 */
		void ModifyBookInRepo(const std::string &titleSearch, const std::string &authorSearch, const std::string &title = "", const std::string &author = "", const std::string &genre = "", const int &releaseYear = 0);

		/**
		 * Deletes a book from the repo, searching by title and author
		 *
		 * @param titleSearch The title to search by
		 * @param authorSearch The author to search by
		 */
		void DeleteBookFromRepo(const std::string &titleSearch, const std::string &authorSearch);
};
