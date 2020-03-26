#include "./clients.h"

LibraryClient::LibraryClient(LibraryService libraryService)
{
	this->setLibraryService(libraryService);
	this->setIO(TerminalIO());
}

LibraryClient::~LibraryClient()
{
	this->setLibraryService(LibraryService());
}

void LibraryClient::ExitApplication()
{
	this->io.PrintString("Exiting application...\n\n");
	exit(0);
}

void LibraryClient::RunApplication()
{
	this->io.PrintString("===== Library App =====\n\n");
	std::string options;
	options = "  [0]: Exit application\n";
	while (true)
	{
		this->io.PrintMenu(options);
		this->io.PrintString("Please input a command: ");
		int command = this->io.ReadInt();
		this->io.PrintString("\n");
		this->io.PrintString("=======================\n\n");
		switch (command)
		{
			case 0: 
				this->ExitApplication();
				break;

			default:
				this->io.PrintString("Invalid command!\n\n");
				break;
		}
		this->io.PrintString("=======================\n\n");
	}
}

