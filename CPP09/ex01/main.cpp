#include <string>
#include <regex>
#include <iostream>
#include <RPN.hpp>

int main(int argc, char **argv)
{
	std::regex pattern(R"(^([1-9\*\/\-\+]\s)*([1-9\*\/\-\+]\s?)$)");

	if (argc < 2)
	{
		std::cerr << "Invalid argument count! should be at least 1" << std::endl;
		return (1);
	}
	std::smatch match;
	std::string argument;
	for (int i = 1; i < argc; i++)
	{
		argument = argv[i];
		if (std::regex_match(argument, match, pattern))
		{
			solve_rpn(argument);
		}
		else
		{
			std::cerr << "Invalid argument!" << std::endl;
		}
	}
}