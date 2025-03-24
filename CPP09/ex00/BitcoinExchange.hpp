#pragma once
#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

#include <sstream>
#include <map>
#include <set>

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
	std::set<std::string> exchange_dates_;
};

#endif // BITCOIN_EXCHANGE