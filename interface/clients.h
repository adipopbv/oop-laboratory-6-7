#pragma once

#include <vector>
#include <string>

#include "../business/services.h"
#include "./graphical_interface/terminal_io.h"
#include "../domain/entities.h"

class LibraryClient
{
	private:
		/// Book service
		LibraryService libraryService = LibraryService();

		/// Terminal input and output operations handler
		TerminalIO io;

		// Library service getter
		LibraryService getLibraryService() { return this->libraryService; }
		// Library service setter
		void setLibraryService(LibraryService value) { this->libraryService = value; }

		// Io getter
		TerminalIO getIO() { return this->io; }
		// Io setter
		void setIO(TerminalIO value) { this->io = value; }

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
