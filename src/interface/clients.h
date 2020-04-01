#pragma once

#include <string>

#include "../business/services.h"
#include "../infrastructure/repos.h"
#include "./graphical-interface/terminal-io.h"
#include "../domain/entities.h"

class LibraryClient
{
	private:
		/// Book service
		LibraryService libraryService = LibraryService();

		/// Terminal input and output operations handler
		const TerminalIO io;

		/// Library service getter
		LibraryService getLibraryService() const { return this->libraryService; }
		/// Library service setter
		void setLibraryService(LibraryService const value) { this->libraryService = value; }

		/// Io getter
		TerminalIO getIO() const { return this->io; }

		/// Lists all books
		void ListAllBooks() const;

		/// Adds book to the repository
		void AddBook();

		/// Modifies a book from the repository
		void ModifyBook();

		/// Deletes a book from the repository
		void DeleteBook();

		/// Exits application
		void ExitApplication() const;

	public:
		/// Library client constructor
		LibraryClient(const LibraryService &libraryService);

		/// Library client destructor
		~LibraryClient();

		/// Main application loop holder
		void RunApplication();
};
