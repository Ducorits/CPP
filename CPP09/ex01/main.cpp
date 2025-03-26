#include <stack>
#include <string>
#include <regex>
#include <iostream>

int main(int argc, char **argv)
{
	std::stack<std::string> stack;

	std::regex pattern(R"(^[1-9\*\/\-\+\s]*$)");

	if (argc < 2)
	{
		std::cerr << "Invalid argument count! should be at least 1" << std::endl;
		return (1);
	}
}