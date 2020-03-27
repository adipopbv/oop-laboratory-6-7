#pragma once

#include <vector>
#include <string>

#include "../domain/entities.h"

class LibraryService
{
	private:
		/// The books repository
		std::vector<Book> booksRepo = std::vector<Book>();

	public:
		/// Library service constructor
		LibraryService(std::vector<Book> booksRepo = std::vector<Book>());

		/// Library service destructor
		~LibraryService();

		/// Books repository getter
		std::vector<Book> getBooksRepo() { return this->booksRepo; }
		/// Books repository setter
		void setBooksRepo(std::vector<Book> value) { this->booksRepo = value; }

		/**
		 * Gets books from the repo
		 *
		 * @param title Filter by title of the book
		 * @param releaseYear Filter by release year of the book
		 */
		std::vector<Book> GetBooks(std::string title, int releaseYear);
		std::vector<Book> GetBooks(std::string title);
		std::vector<Book> GetBooks(int releaseYear);
		std::vector<Book> GetBooks();

		/**
		 * Adds a book to the repo
		 *
		 * @param title The title of the book
		 * @param author The author of the book
		 * @param genre The genre of the book
		 * @param releaseYear The release year of the book
		 */
		void AddBookToRepo(std::string title = "", std::string author = "", std::string genre = "", int releaseYear = 0);

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
		void ModifyBookInRepo(std::string titleSearch, std::string authorSearch, std::string title = "", std::string author = "", std::string genre = "", int releaseYear = 0);
};
