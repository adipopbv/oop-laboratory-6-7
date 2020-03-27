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

void LibraryClient::AddBook()
{
	this->io.PrintString("Add book\n");
	std::string title = this->io.ReadString("  Title: ");
	std::string author = this->io.ReadString("  Author: ");
	std::string genre = this->io.ReadString("  Genre: ");
	int releaseYear = this->io.ReadInt("  Release year: ");

	this->io.PrintString("\n");
	this->libraryService.AddBookToRepo(title, author, genre, releaseYear);
	this->io.PrintString("Operation succesful!\n\n");
}

void LibraryClient::ListAllBooks()
{
	std::vector<Book> books = this->libraryService.GetBooks();
	if (books.size() <= 0)
	{
		this->io.PrintString("No books to show!\n\n");
		return;
	}
	for (int i = 0; i < (int)books.size(); i++)
	{
		this->io.PrintString("~~~~~~~~~~\n");
		this->io.PrintString("  title: " + books[i].getTitle() + "\n" +
			"  author: " + books[i].getAuthor() + "\n" +
			"  genre: " + books[i].getGenre() + "\n" +
			"  release year: " + std::to_string(books[i].getReleaseYear()) + "\n");
	}
	this->io.PrintString("~~~~~~~~~~\n\n");
}

void LibraryClient::ExitApplication()
{
	this->io.PrintString("Exiting application...\n\n");
	exit(0);
}

void LibraryClient::RunApplication()
{
	this->io.PrintString("===== Library App =====\n\n");
	std::string options = "";
	options = options + 
		"  [0]: Exit application\n" + 
		"  [1]: List all books\n" + 
		"  [2]: Add book\n";
	while (true)
	{
		this->io.PrintMenu(options);
		int command = this->io.ReadInt("Please input a command: ");
		this->io.PrintString("\n=======================\n\n");
		switch (command)
		{
			case 0: 
				this->ExitApplication();
				break;

			case 1:
				this->ListAllBooks();
				break;

			case 2:
				this->AddBook();
				break;

			default:
				this->io.PrintString("Invalid command!\n\n");
				break;
		}
		this->io.PrintString("=======================\n\n");
	}
}

