#pragma once

#include <iostream>
#include <string>
#include <exception>

/// Handles input and output operations for terminal applications
class TerminalIO
{
	public:
		/// Terminal gui constructor
		TerminalIO();

		/// Terminal gui destructor
		~TerminalIO();

		/**
		 * Reads an integer from the terminal
		 *
		 * @param prompt Message to print before reading input
		 * @returns The read integer
		 */
		int ReadInt(std::string prompt = "");

		/**
		 * Reads a line of characters from the terminal
		 *
		 * @param prompt Message to print before reading input
		 * @returns The read string of characters
		 */
		std::string ReadString(std::string prompt = "");

		/**
		 * Prints a message in the terminal
		 *
		 * @param message The message to be displayed
		 */
		void PrintString(std::string message);

		/**
		 * Prints the application menu in the terminal
		 *
		 * @param options The options list to be displayed
		 */
		void PrintMenu(std::string options);
};
