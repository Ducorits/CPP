#include <stack>
#include <string>
#include <regex>
#include <iostream>

void solve_rpn(std::string argument)
{
	std::stack<double> stack;
	double a;
	double b;

	for (auto it = argument.begin(); it != argument.end(); it++)
	{
		if (isdigit(*it))
		{
			stack.push(std::stod(&*it));
		}
		else if (*it == ' ')
		{
			continue;
		}
		else
		{
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			if (*it == '+')
				stack.push(a + b);
			else if (*it == '-')
				stack.push(a - b);
			else if (*it == '/')
				stack.push(a / b);
			else if (*it == '*')
				stack.push(a * b);
		}
	}
	std::cout << stack.top() << std::endl;
}

int main(int argc, char **argv)
{
	std::regex pattern(R"(^([1-9\*\/\-\+]\s)*([1-9\*\/\-\+]\s?)$)");

	if (argc < 2)
	{
		std::cerr << "Invalid argument count! should be at least 1" << std::endl;
		return (1);
	}
	std::smatch match;
	std::string argument(argv[1]);
	if (std::regex_match(argument, match, pattern))
	{
		solve_rpn(argument);
	}
	else
	{
		std::cerr << "Invalid argument: " << argument << std::endl;
	}
}