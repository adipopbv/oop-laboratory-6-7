#pragma once

#include <string>

class Book
{
	private:
		/// The title of the book
		std::string title = "";

		/// The author of the book
		std::string author = "";

		/// The genre of the book
		std::string genre = "";

		/// The release year of the book
		int releaseYear = 0;

	public:
		/// Overloading == operator
		bool operator== (Book other);

		/// Book constructor
		Book(std::string title = "None", std::string author = "None", std::string genre = "None", int releaseYear = 0);

		/// Book destructor
		~Book();

		/// Title getter
		std::string getTitle() { return this->title; }
		/// Title setter
		void setTitle(std::string value) { this->title = value; }

		/// Author getter
		std::string getAuthor() { return this->author; }
		/// Author setter
		void setAuthor(std::string value) { this->author = value; }

		/// Genre getter
		std::string getGenre() { return this->genre; }
		/// Genre setter
		void setGenre(std::string value) { this->genre = value; }

		/// Release year getter
		int getReleaseYear() { return this->releaseYear; }
		/// Release year setter
		void setReleaseYear(int value) { this->releaseYear = value; }
};
