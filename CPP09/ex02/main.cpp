#include <iostream>
#include <regex>
#include <vector>
#include <deque>
#include <chrono>
#include <PmergeMe.hpp>

int PmergeMe(char **argv)
{
	std::deque<number_t *> num_deq;
	std::vector<number_t *> num_vec;

	std::regex pattern(R"(^[0-9]+$)");

	std::smatch match;
	std::string argument;
	for (int i = 1; argv[i]; i++)
	{
		argument = argv[i];
		if (std::regex_match(argument, match, pattern))
		{
			try
			{
				int num = std::stoi(argument);

				number_t *numt = new number_t;
				number_t *numpty = new number_t;
				numt->index = num_vec.size() - 1;
				numt->value = num;
				numt->loser = 0;
				numt->winner = 0;
				numpty->index = num_deq.size() - 1;
				numpty->value = num;
				numpty->loser = 0;
				numpty->winner = 0;
				num_vec.push_back(numt);
				num_deq.push_back(numpty);
			}
			catch (std::exception &e)
			{
				std::cerr << "Error: number is invalid. (Over maxint etc)" << std::endl;
				return 1;
			}
		}
		else
		{
			std::cerr << "Error: Invalid argument!" << std::endl;
			return (1);
		}
	}

	std::cout << "Before sort:" << std::endl;
	print_numcon<std::vector<number_t *>>(num_vec);

	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	fordJohnsonSortCon(num_vec);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	std::chrono::high_resolution_clock::time_point begin2 = std::chrono::high_resolution_clock::now();
	fordJohnsonSortCon(num_deq);
	std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();

	std::cout << "After sort:" << std::endl;
	print_numcon<std::vector<number_t *>>(num_vec);

	// Print timing
	std::chrono::microseconds elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::chrono::microseconds elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);

	std::cout << "Time to sort " << num_vec.size() << " elements using std::vector: " << elapsed.count() << " us" << std::endl;
	std::cout << "Time to sort " << num_deq.size() << " elements using std::deque: " << elapsed2.count() << " us" << std::endl;

	for (auto value : num_vec)
		delete value;
	for (auto value : num_deq)
		delete value;

	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	else
	{
		return (PmergeMe(argv));
	}
}
