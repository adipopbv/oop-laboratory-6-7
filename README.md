# Object Oriented Programming - Laboratory 6-7

## Table of Contents

- [Details](#Details)
- [Assignments](#Assignments)
	- [Code specifications](#Code-specifications)
	- [App specifications](#App-specifications)
- [Solution](#Solution)
	- [Iteration 1](#Iteration-1)

## Details

A __library management__ application.

OOP Laboratory 6-7 project source files.

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

__Note__: everything done at runtime will not be saved to disk!

