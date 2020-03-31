#pragma once

#include <vector>
#include <string>

#include "../business/services.h"
#include "./graphical-interface/terminal-io.h"
#include "../domain/entities.h"

class LibraryClient
{
	private:
		/// Book service
		LibraryService libraryService = LibraryService();

		/// Terminal input and output operations handler
		TerminalIO io;

		/// Library service getter
		LibraryService getLibraryService() { 
			return this->libraryService; 
		}
		/// Library service setter
		void setLibraryService(LibraryService value) { this->libraryService = value; }

		/// Io getter
		TerminalIO getIO() { return this->io; }
		/// Io setter
		void setIO(TerminalIO value) { this->io = value; }

		/// Lists all books
		void ListAllBooks();

		/// Adds book to the repository
		void AddBook();

		/// Modifies a book from the repository
		void ModifyBook();

		/// Deletes a book from the repository
		void DeleteBook();

		/// Exits application
		void ExitApplication();

	public:
		/// Library client constructor
		LibraryClient(LibraryService libraryService);

		/// Library client destructor
		~LibraryClient();

		/// Main application loop holder
		void RunApplication();
};
