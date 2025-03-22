#include <BitcoinExchange.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

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

void process_input(std::stringstream &iss, BitcoinExchange &btc)
{
	std::string line;
	// Skip first line. (date, exchange_rate)
	std::getline(iss, line);
	while (std::getline(iss, line))
	{
		// validate_line(line);
		std::stringstream line_stream(line);
		std::string date, value;
		std::getline(line_stream, date, '|');
		date.erase(date.length() - 1, 1);
		std::getline(line_stream, value);

		float fvalue = std::stof(value);
		float rate = btc.get_rate_for_date(date);

		std::cout << date << " => " << value << " = " << (fvalue * rate) << std::endl;
	}
}

int main(int argc, char **argv)
{
	std::stringstream data_ss;
	std::stringstream input_ss;
	BitcoinExchange btc;

	// std::set<std::string> test_set = {"2009-02-04", "2008-02-01", "2009-02-02", "2009-01-20"};

	// for (auto i : test_set)
	// {
	// 	std::cout << i << std::endl;
	// }

	try
	{
		validate_arguments(argc, argv);
		input_ss = read_file(argv[1]);
		if (argc == 3)
			data_ss = read_file(argv[2]);
		else
			data_ss = read_file((char *)"data.csv");
		btc.fill_database(data_ss);
		process_input(input_ss, btc);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}