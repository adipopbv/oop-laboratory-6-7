#include "./clients.h"

LibraryClient::LibraryClient(const LibraryService &libraryService) :io(TerminalIO())
{
	this->setLibraryService(libraryService);
}

LibraryClient::~LibraryClient()
{
	this->setLibraryService(LibraryService());
}

void LibraryClient::PrintBook(Book const book) const
{
	this->getIO().PrintString(
		"  ┌─Title: " + book.getTitle() + "\n" +
		"  ├─Author: " + book.getAuthor() + "\n" +
		"  ├─Genre: " + book.getGenre() + "\n" +
		"  └─Release year: " + std::to_string(book.getReleaseYear()) + "\n"
	);
}

void LibraryClient::ListAllBooks() const
{
	Repo<Book> books = this->getLibraryService().GetBooks();
	if (books.Empty())
	{
		this->getIO().PrintString("»No books to show!\n\n");
		return;
	}
	for (int i = 0; i < static_cast<int>(books.Size()); i++)
	{
		this->getIO().PrintString("──────────\n");
		this->PrintBook(books[i]);
	}
	this->getIO().PrintString("──────────\n\n");
}

void LibraryClient::AddBook()
{
	this->getIO().PrintString("»»Add book\n");
	this->getIO().PrintString("  ╚═Book to be added:\n");
	std::string title = this->getIO().ReadString("    ├─Title: ");
	std::string author = this->getIO().ReadString("    ├─Author: ");
	std::string genre = this->getIO().ReadString("    ├─Genre: ");
	int releaseYear = this->getIO().ReadInt("    └─Release year: ");

	this->getIO().PrintString("\n");
	this->libraryService.AddBookToRepo(title, author, genre, releaseYear);
	this->getIO().PrintString("»Operation succesful!\n\n");
}

void LibraryClient::ModifyBook()
{
	this->getIO().PrintString("»»Modify book\n");
	this->getIO().PrintString("  ╠═Book to be modified:\n");
	std::string titleSearch = this->getIO().ReadString("  ║ ├─Title: ");
	std::string authorSearch = this->getIO().ReadString("  ║ └─Author: ");
	this->getIO().PrintString("  ╚═New book values (leave field empty to not modify):\n");
	std::string title = this->getIO().ReadString("    ├─Title: ");
	std::string author = this->getIO().ReadString("    ├─Author: ");
	std::string genre = this->getIO().ReadString("    ├─Genre: ");
	int releaseYear = this->getIO().ReadInt("    └─Release year: ");

	this->getIO().PrintString("\n");
	this->libraryService.ModifyBookInRepo(titleSearch, authorSearch, title, author, genre, releaseYear);
	this->getIO().PrintString("»Operation succesful!\n\n");
}

void LibraryClient::DeleteBook()
{
	this->getIO().PrintString("»»Delete book\n");
	this->getIO().PrintString("  ╚═Book to be deleted:\n");
	std::string titleSearch = this->getIO().ReadString("    ├─Title: ");
	std::string authorSearch = this->getIO().ReadString("    └─Author: ");

	this->getIO().PrintString("\n");
	this->libraryService.DeleteBookFromRepo(titleSearch, authorSearch);
	this->getIO().PrintString("»Operation succesful!\n\n");
}

void LibraryClient::SearchBook()
{
	this->getIO().PrintString("»»Search book\n");
	this->getIO().PrintString("  ╚═Fields to search by (leave field empty to ignore):\n");
	std::string titleSearch = this->getIO().ReadString("    ├─Title: ");
	std::string authorSearch = this->getIO().ReadString("    ├─Author: ");
	std::string genreSearch = this->getIO().ReadString("    ├─Genre: ");
	int releaseYearSearch = this->getIO().ReadInt("    └─Release year: ");

	this->getIO().PrintString("\n");
	Book searchedBook = this->libraryService.SearchBook(titleSearch, authorSearch, genreSearch, releaseYearSearch);
	this->getIO().PrintString("──────────\n");
	this->PrintBook(searchedBook);
	this->getIO().PrintString("──────────\n\n");
}

void LibraryClient::FilterBooks()
{
	this->getIO().PrintString("»»Filter books\n");
	this->getIO().PrintString("  ╚═Fields to filter by:\n");
	this->getIO().PrintString("    ╠═[1]: Title\n");
	this->getIO().PrintString("    ╚═[2]: Release year\n");

	std::string titleFilter;
	int releaseYearSearch;
	Repo<Book> filteredBooks;

	this->getIO().PrintString("\n");
	int option = this->getIO().ReadInt("»Enter option: ");
	this->getIO().PrintString("\n");
	switch (option)
	{
		case 1:
			titleFilter = this->getIO().ReadString("»Enter title: ");
			this->getIO().PrintString("\n");
			filteredBooks = this->getLibraryService().GetFilteredBooks(titleFilter);
			break;

		case 2:
			releaseYearSearch = this->getIO().ReadInt("»Enter release year: ");
			this->getIO().PrintString("\n");
			filteredBooks = this->getLibraryService().GetFilteredBooks(releaseYearSearch);
			break;

		default:
			this->getIO().PrintString("»Invalid command!\n\n");
			return;
			break;
	}
	for (int i = 0; i < filteredBooks.Size(); i++)
	{
		this->getIO().PrintString("──────────\n");
		this->PrintBook(filteredBooks[i]);
	}
	this->getIO().PrintString("──────────\n\n");
}

void LibraryClient::SortBooks()
{
	this->getIO().PrintString("»»Sort books\n");
	this->getIO().PrintString("  ╚═Fields to sort by:\n");
	this->getIO().PrintString("    ╠═[1]: Title\n");
	this->getIO().PrintString("    ╠═[2]: Author\n");
	this->getIO().PrintString("    ╚═[3]: Release year and genre\n");

	this->getIO().PrintString("\n");
	int option = this->getIO().ReadInt("»Enter option: ");
	this->getIO().PrintString("\n");
	switch (option)
	{
		case 1:
			this->getIO().PrintString("\n");
			this->getLibraryService().SortBooksByTitle();
			break;

		case 2:
			this->getIO().PrintString("\n");
			this->getLibraryService().SortBooksByAuthor();
			break;

		case 3:
			this->getIO().PrintString("\n");
			this->getLibraryService().SortBooksByReleaseYearAndGenre();
			break;

		default:
			this->getIO().PrintString("»Invalid command!\n\n");
			return;
			break;
	}

	this->ListAllBooks();
}

void LibraryClient::ExitApplication() const
{
	this->getIO().PrintString("»Exiting application...\n\n");
	this->getLibraryService().getBooksRepo().FreeRepo();
}

void LibraryClient::RunApplication()
{
	this->getIO().PrintString("═════ Library App ═════\n\n");
	std::string options = "";
	options = options + 
		"  ╠═[0]: Exit application\n" + 
		"  ╠═[1]: List all books\n" + 
		"  ╠═[2]: Add book\n" +
		"  ╠═[3]: Modify book\n" +
		"  ╠═[4]: Delete book\n" +
		"  ╠═[5]: Search book\n" +
		"  ╠═[6]: Filter books\n" +
		"  ╚═[7]: Sort books\n";
	while (true)
	{
		try
		{
			this->getIO().PrintMenu(options);
			int command = this->getIO().ReadInt("»Please input a command: ");
			this->getIO().PrintString("\n═══════════════════════\n\n");
			switch (command)
			{
				case 0: 
					this->ExitApplication();
					return;
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
	
				case 4:
					this->DeleteBook();
					break;

				case 5:
					this->SearchBook();
					break;

				case 6:
					this->FilterBooks();
					break;

				case 7:
					this->SortBooks();
					break;
	
				default:
					this->getIO().PrintString("»Invalid command!\n\n");
					break;
			}
		}
		catch (AppException& e)
		{
			this->getIO().PrintString("»Error: " + e.getMessage() + "\n\n");
		}
		this->getIO().PrintString("═══════════════════════\n\n");
	}
}

