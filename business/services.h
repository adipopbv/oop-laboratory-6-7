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
};
