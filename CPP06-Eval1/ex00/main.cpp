#include <ScalarConverter.hpp>
#include <iostream>


int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Program needs one argument" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cout << "Too many arguments, program takes only 1 argument" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	return (0);
}
