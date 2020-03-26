#pragma once

#include <iostream>
#include <string>

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
		 * @returns The read integer
		 */
		int ReadInt();

		/**
		 * Reads a line of characters from the terminal
		 *
		 * @returns The read string of characters
		 */
		std::string ReadString();

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
