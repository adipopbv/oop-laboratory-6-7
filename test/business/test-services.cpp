#include <gtest/gtest.h>
#include "../../src/business/services.h"

TEST(LibraryService, GetBooks)
{
	Repo<Book> books = Repo<Book>();
	Book book = Book("ceva", "cineva", "careva", 2020);
	books.Add(book);
	LibraryService service = LibraryService();
	ASSERT_THROW(service.GetBooks()[0], EmptyRepoError);
	ASSERT_THROW(service.GetBooks("ceva", 2020)[0], EmptyRepoError);
	service.getBooksRepo().FreeRepo();
	service = LibraryService(books);
	ASSERT_TRUE(service.GetBooks()[0] == books[0]);
	ASSERT_TRUE(service.GetBooks("ceva", 2020)[0] == books[0]);
	books.FreeRepo();
}

TEST(LibraryService, AddBookToRepo)
{
	Book book1 = Book("ceva", "cineva", "careva", 2020);
	Book book2 = Book("ce", "se", "intampla", 301);
	LibraryService service = LibraryService();
	service.AddBookToRepo("ceva", "cineva", "careva", 2020);
	service.AddBookToRepo("ce", "se", "intampla", 301);
	ASSERT_TRUE(service.GetBooks()[0] == book1);
	ASSERT_TRUE(service.GetBooks()[1] == book2);
	ASSERT_THROW(service.AddBookToRepo("ce", "se", "petrece", 123), DuplicateError);
	ASSERT_THROW(service.AddBookToRepo("", "", "", -3), ValidationError);
	ASSERT_TRUE(service.GetBooks().Size() == 2);
	service.getBooksRepo().FreeRepo();
}

TEST(LibraryService, ModifyBookInRepo)
{
	Book book1 = Book("ceva", "cineva", "careva", 2020);
	Book book2 = Book("ce", "se", "intampla", 301);
	Book book3 = Book("vai", "de", "noi", 2020);
	LibraryService service = LibraryService();
	service.AddBookToRepo("ceva", "cineva", "careva", 2020);
	service.AddBookToRepo("ce", "se", "intampla", 301);
	ASSERT_THROW(service.ModifyBookInRepo("ceva", "cineva", "ce", "se", "intampla", 301), DuplicateError);
	ASSERT_THROW(service.ModifyBookInRepo("ceva", "cineva", "", "", "", -88), ValidationError);
	ASSERT_THROW(service.ModifyBookInRepo("", "a", "", "", "", -3), SearchFieldsError);
	ASSERT_THROW(service.ModifyBookInRepo("haa", "yaa", "", "", "", 1), NotFoundError);
	service.ModifyBookInRepo("ceva", "cineva", "vai", "de", "noi", 2020);
	ASSERT_TRUE(service.GetBooks()[0] == book3);
	ASSERT_TRUE(service.GetBooks().Size() == 2);
	service.getBooksRepo().FreeRepo();
}

TEST(LibraryService, DeleteBookFromRepo)
{
	Book book1 = Book("ceva", "cineva", "careva", 2020);
	Book book2 = Book("ce", "se", "intampla", 301);
	LibraryService service = LibraryService();
	service.AddBookToRepo("ceva", "cineva", "careva", 2020);
	service.AddBookToRepo("ce", "se", "intampla", 301);
	ASSERT_THROW(service.DeleteBookFromRepo("a", ""), SearchFieldsError);
	ASSERT_THROW(service.DeleteBookFromRepo("a", "b"), NotFoundError);
	service.DeleteBookFromRepo("ceva", "cineva");
	ASSERT_TRUE(service.GetBooks()[0] == book2);
	ASSERT_TRUE(service.GetBooks().Size() == 1);
	service.getBooksRepo().FreeRepo();
}

TEST(LibraryService, SearchBook)
{
	Book book1 = Book("ceva", "cineva", "careva", 2020);
	Book book2 = Book("ceva", "se", "intampla", 301);
	LibraryService service = LibraryService();
	service.AddBookToRepo("ceva", "cineva", "careva", 2020);
	service.AddBookToRepo("ceva", "se", "intampla", 301);
	ASSERT_THROW(service.SearchBook("", "", "", -1), SearchFieldsError);
	ASSERT_THROW(service.SearchBook("a", "b", "c", 1), NotFoundError);
	ASSERT_TRUE(service.SearchBook("ceva", "", "", -1) == book1);
	ASSERT_TRUE(service.SearchBook("ceva", "", "intampla", -1) == book2);
	service.getBooksRepo().FreeRepo();
}

