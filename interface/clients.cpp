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

void LibraryClient::RunApplication()
{
	io.PrintMessage("Application started...");
	/*
	while (true)
	{

	}
	*/
}

