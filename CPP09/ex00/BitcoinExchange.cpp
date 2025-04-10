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

// Date is the key value inside of our exchange history map. We use the lower_bound() method to find the date if it exists, otherwise it returns the date GREATER than our query. We lower the iterator by 1 to find the date we actually need.
float BitcoinExchange::get_rate_for_date(std::string date)
{
	float rate = 0;

	try
	{
		auto date_iter = exchange_history_.lower_bound(date);
		if (date_iter->first != date)
		{
			if (date_iter != exchange_history_.begin())
				date_iter--;
			else
				throw(std::runtime_error("No exchange history found!"));
		}
		rate = date_iter->second;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return rate;
}