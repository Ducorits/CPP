#include <ScalarConverter.hpp>
#include <string>
#include <iostream>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

/* converts a string representation of a c++
literal in its most common form and output its
value in the following serie of scalar types:
Char, int, float, double.
*/
void ScalarConverter::convert(std::string str)
{
	double	doubler;
	int		integer;
	float	floater;
	char	character;

	if (str.size() == 1)
	{
		std::cout << "is char" << std::endl;
		integer = std::stoi(str);
		if (std::isprint(integer))
		{
			std::cout << "is printable" << std::endl;
		}
	}
	if (str.find('.'))
	{
		std::cout << "has dot" << std::endl;
		if (str.back() == 'f')
		{
			std::cout << "is float" << std::endl;
		}
	}
	floater = std::stof(str);
	doubler = std::stod(str);
	integer = std::stoi(str);
	character = std::stoi(str);

	std::cout << "char: " << character << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << floater << std::endl;
	std::cout << "double: " << doubler << std::endl;
}