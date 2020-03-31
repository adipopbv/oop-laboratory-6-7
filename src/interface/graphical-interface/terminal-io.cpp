#include "./terminal-io.h"

TerminalIO::TerminalIO() { }

TerminalIO::~TerminalIO() { }

int TerminalIO::ReadInt(std::string prompt)
{
	this->PrintString(prompt);
	std::string input = this->ReadString();
	try { return std::stoi(input); } 
	catch (std::exception& e) { return -1; }
	return -1;
}

std::string TerminalIO::ReadString(std::string prompt)
{
	this->PrintString(prompt);
	std::string value = "";
	std::getline(std::cin, value, '\n');
	return value;
}

void TerminalIO::PrintString(std::string message)
{
	std::cout << message;
}

void TerminalIO::PrintMenu(std::string options)
{
	this->PrintString("»»Menu\n");
	this->PrintString(options);
	this->PrintString("\n");
}

