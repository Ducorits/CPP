#include <Span.hpp>
#include <iostream>
#include <numeric>

int main()
{

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "printing span:" << std::endl;
	sp.print();

	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(100);
	vec.push_back(1);
	vec.push_back(88);
	vec.push_back(1111111);
	vec.push_back(55);
	vec.push_back(-2147483647);
	vec.push_back(-2147483648);
	Span s(vec.size());

	try
	{
		s.AddRange(vec.begin(), vec.end());
		std::cout << "---------------------------" << std::endl;
		std::cout << "Printing range filled span:" << std::endl;
		s.print();
		std::cout << "--------SPANS-------------" << std::endl;
		std::cout << "shortest " << s.shortestSpan() << std::endl;
		std::cout << "longest " << s.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::vector<int> vec2(100000);
	std::iota(vec2.begin(), vec2.end(), 1);

	Span sp2(vec2.size());
	try
	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Fill VERY big span" << std::endl;
		sp2.AddRange(vec2.begin(), vec2.end());
		std::cout << "--------SPANS-------------" << std::endl;
		std::cout << "shortest " << sp2.shortestSpan() << std::endl;
		std::cout << "longest " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// Try to add even more!
	try
	{
		sp2.AddRange(vec2.begin(), vec2.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}