#include <ScalarConverter.hpp>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

static bool is_valid_number(std::string &str)
{
	std::string filter = "-+.0123456789";
	size_t size;

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
	if (str == "+inf" || str == "-inf" || str == "nan" || str == "nanf" || str == "-inff" || str == "+inff" || str == "inf" || str == "inff")
		return (true);
	return (false);
}

static t_type determine_type(std::string &str)
{
	if (str.size() == 1 && !isdigit(str[0]))
	{
		return (CHAR);
	}
	else if ((str.find('.') != static_cast<size_t>(-1) && is_valid_number(str)) || is_pseudo_literal(str))
	{
		if (str.back() == 'f')
		{
			return (FLOAT);
		}
		else
		{
			return (DOUBLE);
		}
	}
	else if (is_valid_number(str))
	{
		return (INT);
	}
	std::cout << "Input is not a valid literal, try using a valid literal." << std::endl;
	return (NONE);
}

template <typename T>
void cast_and_print(T number)
{
	char character;
	int integer;
	float floater;
	double doubler;

	if (number >= std::numeric_limits<char>::min() && number <= std::numeric_limits<char>::max())
	{
		character = static_cast<char>(number);
		if (std::isprint(character))
		{
			std::cout << "char: '" << character << "'" << std::endl;
		}
		else
		{
			std::cout << "char: " << "Non displayable" << std::endl;
		}
	}
	else
		std::cout << "char: impossible" << std::endl;
	if ((int)number >= std::numeric_limits<int>::min() && (int)number <= std::numeric_limits<int>::max())
	{
		integer = static_cast<int>(number);
		std::cout << "Int: " << integer << std::endl;
	}
	else
		std::cout << "Int: impossible" << std::endl;

	if ((number >= std::numeric_limits<float>::lowest() && number <= std::numeric_limits<float>::max()) || std::isnan(number) || std::isinf(number))
	{
		floater = static_cast<float>(number);
		std::cout << "Float: " << std::fixed << std::setprecision(1) << floater << "f" << std::endl;
	}
	else
		std::cout << "Float: impossible" << std::endl;
	doubler = static_cast<double>(number);
	std::cout << "Double: " << std::fixed << std::setprecision(1) << doubler << std::endl;
}

static void charCase(std::string str)
{
	char character;

	character = str[0];
	cast_and_print<char>(character);
}

static void intCase(std::string str)
{
	int integer;

	integer = std::stoi(str);
	cast_and_print<int>(integer);
}

static void floatCase(std::string str)
{
	float floater;

	floater = std::stof(str);
	cast_and_print<float>(floater);
}

static void doubleCase(std::string str)
{
	double doubler;

	doubler = std::stod(str);
	cast_and_print<double>(doubler);
}

static void edgeCase(std::string str)
{
	(void)str;
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
	t_type type;

	type = determine_type(str);
	try
	{
		if (type == CHAR)
		{
			charCase(str);
		}
		if (type == INT)
		{
			intCase(str);
		}
		if (type == FLOAT)
		{
			floatCase(str);
		}
		if (type == DOUBLE)
		{
			doubleCase(str);
		}
		else
		{
			edgeCase(str);
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
}
