#include "./terminal_io.h"


TerminalIO::TerminalIO() { }

TerminalIO::~TerminalIO() { }

int TerminalIO::ReadInt()
{
	int value = 0;
	std::cin >> value;
	return value;
}

std::string TerminalIO::ReadString()
{
	std::string value = "";
	std::cin >> value;
	return value;
}

void TerminalIO::PrintMessage(std::string message)
{
	std::cout << message << "\n";
}
