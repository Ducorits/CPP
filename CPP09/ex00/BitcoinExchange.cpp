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
		this->exchange_dates_.insert(key);
	}
}

// Date is the key value inside of our exchange history map.
// We use a sorted date set to easily retrieve previous rates.
float BitcoinExchange::get_rate_for_date(std::string date)
{
	float rate = 0;

	try
	{
		// first try to find date.
		auto find_iter = exchange_dates_.find(date);
		// if date not found, insert date into sorted set, retrieve rate for date--, set rate for newly inserted date in exchange history.
		if (find_iter == exchange_dates_.end())
		{
			auto [date_it, succes] = exchange_dates_.insert(date);
			if (succes == false)
				throw(std::runtime_error("Failed to retrieve exchange rate"));
			if (date_it == exchange_dates_.begin())
			{
				exchange_dates_.erase(*date_it);
				throw(std::runtime_error("No exchange history found!"));
			}
			rate = exchange_history_.at(*--date_it);
			exchange_history_.insert({*++date_it, rate});
		}
		else
			rate = exchange_history_.at(*find_iter);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << rate << " for [" << date << "]" << std::endl;

	return rate;
}