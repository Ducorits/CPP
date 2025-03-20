#pragma once
#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

#include <sstream>
#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	void fill_database(std::stringstream &ss);
	float get_rate_for_date(std::string date);

private:
	std::map<std::string, float> exchange_history_;
};

#endif // BITCOIN_EXCHANGE