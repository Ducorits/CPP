#include <BitcoinExchange.hpp>
#include <iostream>
#include <fstream>

void validate_input(int argc, char **argv)
{
	if (argc != 3)
		throw std::runtime_error("Invalid argument count, expected 2 arguments: " + std::string(argv[0]) + " <*.csv> <*.txt>");

	std::string data_file_name(argv[1]);
	std::string input_file_name(argv[2]);

	if (data_file_name.rfind(".csv") != data_file_name.length() - 4)
		throw std::invalid_argument("First argument should have .csv extension: [" + data_file_name + "]");
	if (data_file_name.rfind(".text") != data_file_name.length() - 4)
		throw std::invalid_argument("Second argument should have .txt extension: [" + input_file_name + "]");
}

std::stringstream read_file(char *file_name)
{
	std::ifstream data_file_stream;
	std::stringstream buffer;

	data_file_stream.open(file_name);
	if (!data_file_stream.is_open())
		throw std::runtime_error("Unable to open file for reading: " + std::string(file_name));

	buffer << data_file_stream.rdbuf();

	return buffer;
}

int main(int argc, char **argv)
{
	std::stringstream data_ss;
	std::stringstream input_ss;
	try
	{
		validate_input(argc, argv);
		data_ss = read_file(argv[1]);
		input_ss = read_file(argv[2]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}