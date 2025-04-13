#include <stack>
#include <string>
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
			if (stack.empty())
			{
				std::cerr << "Error: Operation on empty stack." << std::endl;
				return;
			}
			a = stack.top();
			stack.pop();
			if (stack.empty())
			{
				std::cerr << "Error: Too few numbers for operation." << std::endl;
				return;
			}
			b = stack.top();
			stack.pop();
			if (*it == '+')
				stack.push(b + a);
			else if (*it == '-')
				stack.push(b - a);
			else if (*it == '/')
				stack.push(b / a);
			else if (*it == '*')
				stack.push(b * a);
		}
	}
	std::cout << stack.top() << std::endl;
}