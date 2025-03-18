#include <BitcoinExchange.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

// Data_file_name is a database
void validate_arguments(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		throw std::runtime_error("Invalid argument count, expected 1 or 2 arguments\n\nUsage:\n  " + std::string(argv[0]) + " <input.txt> [database.csv]");

	std::string input_file_name(argv[1]);
	std::string data_file_name;
	if (argc == 3)
	{
		data_file_name = std::string(argv[2]);
		if (data_file_name.rfind(".csv") != data_file_name.length() - 4)
			throw std::invalid_argument("Second optional argument should have .csv extension: [" + data_file_name + "]");
	}

	if (input_file_name.rfind(".txt") != input_file_name.length() - 4)
		throw std::invalid_argument("First argument should have .txt extension: [" + input_file_name + "]");
}

std::stringstream read_file(char *file_name)
{
	std::ifstream data_file_stream;
	std::stringstream buffer("");

	data_file_stream.open(file_name);
	if (!data_file_stream.is_open())
		throw std::runtime_error("Unable to open file for reading: " + std::string(file_name));

	buffer << data_file_stream.rdbuf();

	return buffer;
}

int validate_input(std::stringstream &iss)
{
	(void)iss;
	return (0);
}

int main(int argc, char **argv)
{
	std::stringstream data_ss;
	std::stringstream input_ss;
	BitcoinExchange btc;

	try
	{
		validate_arguments(argc, argv);
		input_ss = read_file(argv[1]);
		if (argc == 3)
			data_ss = read_file(argv[2]);
		else
			data_ss = read_file((char *)"data.csv");

		validate_input(input_ss);

		btc.fill_database(data_ss);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}