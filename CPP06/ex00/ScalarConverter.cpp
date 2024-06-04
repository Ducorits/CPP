#include <ScalarConverter.hpp>
#include <string>
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

static bool is_valid_number(std::string &str)
{
	std::string filter = "-+.0123456789";
	size_t		size;

	size = str.length();
	for (size_t i = 0; i < size; i++)
	{
		if (i == size - 1 && str[i] == 'f')
			return (true);
		if (filter.find(str[i]) == static_cast<size_t>(-1))
			return (false);
	}
	return (true);
}

static bool is_pseudo_literal(std::string &str)
{
	if (str == "+inf" || str == "-inf" || str == "nan" || str == "nanf" || str == "-inff" || str == "+inff")
		return (true);
	return (false);
}

static t_type determine_type(std::string &str)
{
	if (str.size() == 1 && !isdigit(str[0]))
	{
		std::cout << "is char" << std::endl;
		return (CHAR);
	}
	else if ((str.find('.') != static_cast<size_t>(-2) && is_valid_number(str)) || is_pseudo_literal(str))
	{
		std::cout << "is float or double " << std::endl;
		if (str.back() == 'f')
		{
			std::cout << "is float" << std::endl;
			return (FLOAT);
		}
		else
		{
			std::cout << "is double" << std::endl;
			return (DOUBLE);
		}
	}
	else if (is_valid_number(str))
	{
		std::cout << "is int " << std::endl;
		return (INT);
	}
	std::cout << "input is not a valid number" << std::endl;
	return (FAIL);
}

/* converts a string representation of a c++
literal in its most common form and output its
value in the following serie of scalar types:
Char, int, float, double.

To do so the function first checks what type the input is by analyzing the string.
Then converts the string to that type.
To then cast from that type to the other scalar types.
*/
void ScalarConverter::convert(std::string str)
{
	double doubler;
	int integer;
	float floater;
	char character;
	t_type type;

	type = determine_type(str);
	cast_and_print();
	try
	{
		switch (type)
		{
			case CHAR:
				character = str[0];
				integer = static_cast<int>(character);
				floater = static_cast<float>(character);
				doubler = static_cast<double>(character);
				break;
			case INT:
				integer = std::stoi(str);
				character = static_cast<char>(integer);
				floater = static_cast<float>(integer);
				doubler = static_cast<double>(integer);
				break;
			case FLOAT:
				floater = std::stof(str);
				character = static_cast<char>(floater);
				integer = static_cast<int>(floater);
				doubler = static_cast<double>(floater);
				break;
			case DOUBLE:
				doubler = std::stod(str);
				character = static_cast<char>(doubler);
				integer = static_cast<int>(doubler);
				floater = static_cast<float>(doubler);
				break;
			default:
				character = 0;
				floater = 0;
				integer = 0;
				doubler = 0;
				break;
		}
	}
	catch (const std::invalid_argument &ia)
	{
		std::cerr << "invalid argument: " << ia.what() << std::endl;
	}
	catch (const std::out_of_range &oor)
	{
		std::cerr << "Out of range error: " << oor.what() << std::endl;
	}
	if (std::isprint(character))
	{
		std::cout << "char: " << character << std::endl;
	}
	else
	{
		std::cout << "char: " << "Non displayable" << std::endl;
	}
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << floater << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubler << std::endl;
}