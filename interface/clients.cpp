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

void LibraryClient::ListAllBooks()
{
	std::vector<Book> books = this->libraryService.GetBooks();
	if (books.size() <= 0)
	{
		this->io.PrintString("»No books to show!\n\n");
		return;
	}
	for (int i = 0; i < (int)books.size(); i++)
	{
		this->io.PrintString("──────────\n");
		this->io.PrintString(
			"  ┌─Title: " + books[i].getTitle() + "\n" +
			"  ├─Author: " + books[i].getAuthor() + "\n" +
			"  ├─Genre: " + books[i].getGenre() + "\n" +
			"  └─Release year: " + std::to_string(books[i].getReleaseYear()) + "\n"
		);
	}
	this->io.PrintString("──────────\n\n");
}

void LibraryClient::AddBook()
{
	this->io.PrintString("»»Add book\n");
	this->io.PrintString("  ╚═Book to be added:\n");
	std::string title = this->io.ReadString("    ├─Title: ");
	std::string author = this->io.ReadString("    ├─Author: ");
	std::string genre = this->io.ReadString("    ├─Genre: ");
	int releaseYear = this->io.ReadInt("    └─Release year: ");

	this->io.PrintString("\n");
	this->libraryService.AddBookToRepo(title, author, genre, releaseYear);
	this->io.PrintString("»Operation succesful!\n\n");
}

void LibraryClient::ModifyBook()
{
	this->io.PrintString("»»Modify book\n");
	this->io.PrintString("  ╠═Book to be modified:\n");
	std::string titleSearch = this->io.ReadString("  ║ ├─Title: ");
	std::string authorSearch = this->io.ReadString("  ║ └─Author: ");
	this->io.PrintString("  ╚═New book values (leave empty to not modify):\n");
	std::string title = this->io.ReadString("    ├─Title: ");
	std::string author = this->io.ReadString("    ├─Author: ");
	std::string genre = this->io.ReadString("    ├─Genre: ");
	int releaseYear = this->io.ReadInt("    └─Release year: ");

	this->io.PrintString("\n");
	try
	{
		this->libraryService.ModifyBookInRepo(titleSearch, authorSearch, title, author, genre, releaseYear);
		this->io.PrintString("»Operation succesful!\n\n");
	}
	catch (std::string& s)
	{ this->io.PrintString("»Error: " + s + "!\n\n"); }
}

void LibraryClient::ExitApplication()
{
	this->io.PrintString("»Exiting application...\n\n");
	exit(0);
}

void LibraryClient::RunApplication()
{
	this->io.PrintString("═════ Library App ═════\n\n");
	std::string options = "";
	options = options + 
		"  ╠═[0]: Exit application\n" + 
		"  ╠═[1]: List all books\n" + 
		"  ╠═[2]: Add book\n" +
		"  ╚═[3]: Modify book\n";
	while (true)
	{
		this->io.PrintMenu(options);
		int command = this->io.ReadInt("»Please input a command: ");
		this->io.PrintString("\n═══════════════════════\n\n");
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

			case 3:
				this->ModifyBook();
				break;

			default:
				this->io.PrintString("»Invalid command!\n\n");
				break;
		}
		this->io.PrintString("═══════════════════════\n\n");
	}
}

