#include <BitcoinExchange.hpp>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (&other != this)
	{
		this->exchange_history_ = other.exchange_history_;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::fill_database(std::stringstream &ss)
{
	std::map<std::string, float> database;

	std::string line;
	// Skip first line. (date, exchange_rate)
	std::getline(ss, line);
	while (std::getline(ss, line))
	{
		std::stringstream line_stream(line);
		std::string key, value;
		std::getline(line_stream, key, ',');
		std::getline(line_stream, value);

		float fvalue = std::stof(value);
		this->exchange_history_.insert({key, fvalue});
	}
}

// Date is the key value inside of our exchange history map.
float BitcoinExchange::get_rate_for_date(std::string date)
{
	float rate = 0;
	try
	{
		rate = exchange_history_.at(date);
	}
	catch (std::exception &e)
	{
		e.what();
	}
	std::cout << rate << " for [" << date << "]" << std::endl;

	return rate;
}