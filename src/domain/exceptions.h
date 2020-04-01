#pragma once

#include <string>

class AppException
{
	private:
		/// Exception message
		const std::string message;
	
	public:
		/// Exception constructor
		AppException(std::string const message) :message(message) { }

		/// Message getter
		const std::string getMessage() const { return this->message; }
};

class IndexError: public AppException
{
	public:
		/// Exception constructor
		IndexError(std::string const message) :AppException(message) { }
};

class ValidationError: public AppException
{
	public:
		/// Exception constructor
		ValidationError(std::string const message) :AppException(message) { }
};

class NotFoundError: public AppException
{
	public:
		/// Exception constructor
		NotFoundError(std::string const message) :AppException(message) { }
};

class DuplicateError: public AppException
{
	public:
		/// Exception constructor
		DuplicateError(std::string const message) :AppException(message) { }
};
