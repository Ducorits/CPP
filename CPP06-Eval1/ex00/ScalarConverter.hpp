#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
} t_type;

class ScalarConverter {
public:
	ScalarConverter();
	virtual ~ScalarConverter();
	// Copy constructor
	ScalarConverter(const ScalarConverter &obj);
	// Operator overload
	ScalarConverter &operator=(const ScalarConverter &obj);

	// Add your method declarations here
	static void convert(std::string str);

private:

};

#endif // SCALAR_CONVERTER_HPP