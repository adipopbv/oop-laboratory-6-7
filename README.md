# Object Oriented Programming - Laboratory 6-7

## Table of Contents

- [Details](#details)
- [Installation & usage](#installation--usage)
- [Assignments](#assignments)
	- [Code specifications](#code-specifications)
	- [App specifications](#app-specifications)
- [Solution](#solution)
	- [Iteration 1](#iteration-1)
	- [Iteration 2](#iteration-2)

## Details

A __library management__ application.

The app allows temporary storing of information about books, helps manage a library and acts like a small, temporary database manager for books.

__Notes:__ For now, only a _Command-Line Interface_ (CLI) is available for the app.

## Installation & usage

#### Linux:

__Downloading:__ To download the application, go to the [releases tab](https://github.com/adipopbv/oop-laboratory-6-7/releases) and select the wanted version ([latest version](https://github.com/adipopbv/oop-laboratory-6-7/releases/latest) is recommended).

__Installation:__ No installation needed. Just place the downloaded executable where you want and run it in a terminal.

#### Other platforms:

Support is not currently given for other platforms, but it should be able to run on all Unix-like operating systems and on Windows if compiling the source code manualy with MinGW or Cygwin, as explained [here](https://docs.microsoft.com/en-us/cpp/porting/porting-from-unix-to-win32?view=vs-2019).



## Assignments

### Code specifications:

> Make a c++ console application using object oriented programming paradigm.

> Iteration 1:
> 1. Use std::string and std::vector;
> 2. Do not use pointers;
> 3. Do not use dynamic alocation.

> Iteration 2:
> 1. Replace std::vector with a custom class implemented with simple linked list;
> 2. Data validation and user warnings and errors;
> 3. Make a UML diagram.

### App specifications:

> __Library app__

> Make an app for managing books. Each book is identified by _title_, _author_, _genre_, _release year_. The app should be capable of going the following:

> 1. Display the full list of books
> 2. Basic operations:
>    * Add book
>    * Modify book
>    * Delete book
> 3. Search book
> 4. Filter books by:
>    * Title
>    * Release year
> 5. Sort books by:
>    * Title
>    * Author
>    * Release year and genre

## Solution

### Iteration 1:

Added the base structure of the application, like the library terminal ui, the library service, the book data type and implemented the books repository using `std::vector` and character strings using `std::string`.

Also, I implemented the following functionalities:
1. Exiting application
2. Listing all books
3. Adding book
4. Modifying book
5. Deleting book

__Note__: nothing done at runtime will be saved to disk!

### Iteration 2:

Added tests based on the google unit testing framework, implemented a custom repository with universal simple linked list, added exceptions and validations.

Also, I implemented the following functionalities:
1. Searching book
2. Filtering books by title or release year
3. Sorting books by title, author or release year and genre

__Note__: saving to disk still not supported!
