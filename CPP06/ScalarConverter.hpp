#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
public:
	ScalarConverter();
	ScalarConverter(const std::string& value);
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter& other);

	// Add your method declarations here
	convert();

private:
	std::string m_value;
};

#endif // SCALAR_CONVERTER_HPP