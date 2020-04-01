#include <gtest/gtest.h>
#include "../../src/business/services.h"

TEST(TestLibraryService, GetBooks)
{
	Book book = Book("ceva", "cineva", "careva", 2020);
	Repo<Book> books = Repo<Book>();
	books.Add(book);
	LibraryService service = LibraryService(books);
	ASSERT_TRUE(service.GetBooks()[0] == books[0]);
	ASSERT_TRUE(service.GetBooks(2020)[0] == books[0]);
	ASSERT_TRUE(service.GetBooks("ceva")[0] == books[0]);
	ASSERT_TRUE(service.GetBooks("ceva", 2020)[0] == books[0]);
	books.FreeElements();
}

