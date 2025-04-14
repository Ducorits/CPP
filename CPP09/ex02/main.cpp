// #include <iostream>
// #include <regex>
// #include <vector>
// #include <deque>

// void deqBinaryInsert(std::deque<int> &sorted_deq, int value)
// {
// 	auto pos = std::lower_bound(sorted_deq.begin(), sorted_deq.end(), value);
// 	sorted_deq.insert(pos, value);
// }

// void deqFordJohnsonSort(std::deque<int> &deq)
// {

// 	if (deq.size() <= 1)
// 		return;

// 	std::deque<int> winners;
// 	std::deque<int> losers;

// 	size_t i = 0;
// 	for (; i + 1 < deq.size(); i += 2)
// 	{
// 		if (deq[i] < deq[i + 1])
// 		{
// 			winners.push_back(deq[i + 1]);
// 			losers.push_back(deq[i]);
// 		}
// 		else
// 		{
// 			winners.push_back(deq[i]);
// 			losers.push_back(deq[i + 1]);
// 		}
// 	}
// 	if (i < deq.size())
// 		losers.push_back(deq[i]);

// 	deqFordJohnsonSort(winners);

// 	for (int value : losers)
// 	{
// 		deqBinaryInsert(winners, value);
// 	}

// 	deq = winners;
// }

// void vecBinaryInsert(std::vector<int> &sorted_vec, int value)
// {
// 	auto pos = std::lower_bound(sorted_vec.begin(), sorted_vec.end(), value);
// 	sorted_vec.insert(pos, value);
// }

// void vecFordJohnsonSort(std::vector<int> &vec)
// {

// 	if (vec.size() <= 1)
// 		return;

// 	std::vector<int> winners;
// 	std::vector<int> losers;

// 	size_t i = 0;
// 	for (; i + 1 < vec.size(); i += 2)
// 	{
// 		if (vec[i] < vec[i + 1])
// 		{
// 			winners.push_back(vec[i + 1]);
// 			losers.push_back(vec[i]);
// 		}
// 		else
// 		{
// 			winners.push_back(vec[i]);
// 			losers.push_back(vec[i + 1]);
// 		}
// 	}
// 	if (i < vec.size())
// 		losers.push_back(vec[i]);

// 	vecFordJohnsonSort(winners);

// 	for (int value : losers)
// 	{
// 		vecBinaryInsert(winners, value);
// 	}

// 	vec = winners;
// }

// int PmergeMe(char **argv)
// {
// 	std::vector<int> vec;
// 	std::deque<int> deq;

// 	std::regex pattern(R"(^[0-9]+$)");

// 	std::smatch match;
// 	std::string argument;
// 	for (int i = 1; argv[i]; i++)
// 	{
// 		argument = argv[i];
// 		if (std::regex_match(argument, match, pattern))
// 		{
// 			int num = std::stoi(argument);
// 			vec.push_back(num);
// 			deq.push_back(num);
// 		}
// 		else
// 		{
// 			std::cerr << "Error: Invalid argument!" << std::endl;
// 			return (1);
// 		}
// 	}

// 	vecFordJohnsonSort(vec);
// 	deqFordJohnsonSort(deq);

// 	std::cout << "Vector:" << std::endl;
// 	for (auto value : vec)
// 	{
// 		std::cout << value << " ";
// 	}
// 	std::cout << std::endl;

// 	std::cout << "Deque:" << std::endl;
// 	for (auto value : deq)
// 	{
// 		std::cout << value << " ";
// 	}
// 	std::cout << std::endl;

// 	return 0;
// }

// int main(int argc, char **argv)
// {
// 	if (argc == 1)
// 	{
// 		std::cerr << "Error" << std::endl;
// 		return (1);
// 	}
// 	else
// 	{
// 		return (PmergeMe(argv));
// 	}
// }

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <chrono>

// *********************************************************************
//  PmergeMe class template
//
//  This class implements the Ford–Johnson merge–insertion sort algorithm.
//  It uses two phases:
//    I.  The merge phase is achieved by grouping the input into pairs
//        and sorting each pair (swapping if necessary).
//    II. The insertion phase reinserts the “smaller” elements from the pairs
//        into a sorted “main” sequence, using an optimized binary search
//        guided by the Jacobsthal sequence.
//
//  The algorithm uses an “order” value to control the grouping. It is used
//  recursively until the base case is reached (group size < 2).
//
//  The implementation follows the detailed explanation from the assignment.
//  Note that every container is handled directly without intermediate conversion.
// *********************************************************************

template <typename Container>
class PmergeMe
{
public:
	typedef typename Container::value_type ValueType;
	typedef typename Container::iterator Iterator;

	PmergeMe(const Container &input) : _data(input) {}

	// Start the recursive merge-insertion sort with initial order = 1.
	void sort()
	{
		mergeInsertionSort(_data, 1);
	}

	const Container &getData() const
	{
		return _data;
	}

private:
	Container _data;

	// Computes the k-th Jacobsthal number using the formula:
	//   J(k) = (2^(k+1) + (-1)^k) / 3.
	int Jacobsthal(int k)
	{
		return static_cast<int>(std::round((std::pow(2, k + 1) + std::pow(-1, k)) / 3.0));
	}

	// Insert elements from 'pend' and the optional odd element into 'main'
	// using a binary search enhanced by the Jacobsthal sequence.
	// 'left' contains leftover elements that couldn’t form a full pair.
	// The complete sorted result is then reassembled into 'vec'.
	void insert(Container &main,
							Container &pend,
							ValueType odd,
							Container &left,
							bool isOdd,
							Container &vec)
	{
		Iterator pos;

		if (pend.size() == 1)
		{
			pos = std::upper_bound(main.begin(), main.end(), *pend.begin());
			main.insert(pos, *pend.begin());
			pend.erase(pend.begin());
		}
		else if (pend.size() > 1)
		{
			size_t jc = 3; // starting index in Jacobsthal sequence (as per exercise)
			size_t count = 0;
			while (!pend.empty())
			{
				// Determine the next index using Jacobsthal differences.
				size_t idx = Jacobsthal(static_cast<int>(jc)) - Jacobsthal(static_cast<int>(jc - 1));
				if (idx > pend.size())
					idx = pend.size();
				size_t decrease = 0;
				// Insert idx elements (from the end of the current pending block)
				while (idx)
				{
					// Compute an insertion index using Jacobsthal optimization.
					int targetIndex = Jacobsthal(static_cast<int>(jc + count)) - static_cast<int>(decrease);
					if (targetIndex < 0)
						targetIndex = 0;
					if (static_cast<size_t>(targetIndex) > main.size())
						pos = main.end();
					else
						pos = main.begin() + targetIndex;
					// Use upper_bound on the range [main.begin(), pos] for insertion.
					pos = std::upper_bound(main.begin(), pos, *(pend.begin() + idx - 1));
					main.insert(pos, *(pend.begin() + idx - 1));
					pend.erase(pend.begin() + idx - 1);
					--idx;
					++decrease;
					++count;
				}
				++jc;
			}
		}

		if (isOdd)
		{
			pos = std::upper_bound(main.begin(), main.end(), odd);
			main.insert(pos, odd);
		}

		// Rebuild the sorted container.
		// According to the exercise, we take sorted segments from the old container.
		// Here we simply rebuild by concatenating the main chain and the leftover.
		Container newContainer;
		std::copy(main.begin(), main.end(), std::back_inserter(newContainer));
		std::copy(left.begin(), left.end(), std::back_inserter(newContainer));
		vec = newContainer;
	}

	// The recursive merge–insertion sort function.
	// 'order' indicates the current grouping size.
	void mergeInsertionSort(Container &vec, int order)
	{
		size_t numGroups = vec.size() / static_cast<size_t>(order);
		if (numGroups < 2)
			return; // Nothing to merge if only one group is left.

		// Determine whether there is an odd group.
		bool isOdd = (numGroups % 2 == 1);

		Iterator start = vec.begin();
		// Exclude the last odd group if it exists.
		Iterator end = vec.begin() + (order * numGroups) - (isOdd ? order : 0);

		// --- Pairwise Comparisons and Swaps (Merging Step) ---
		// For every two adjacent groups, compare the last element of each group
		// and swap the groups if the first group's last element is larger.
		for (Iterator it = start; it < end; it += (order * 2))
		{
			// Compare the last element of the first group with the last element of the second group.
			if (*(it + (order - 1)) > *(it + (order * 2 - 1)))
			{
				// Swap the two groups element by element.
				for (int i = 0; i < order; i++)
				{
					std::swap(*(it + i), *(it + i + order));
				}
			}
		}

		// --- Recurse on the main sequence ---
		// Increase the order and recursively merge.
		mergeInsertionSort(vec, order * 2);

		// --- After recursion, prepare for the insertion phase ---
		// We form two separate containers: main and pend.
		Container main;
		Container pend;
		ValueType odd = ValueType(); // valid if isOdd is true
		Container left;

		// The first group's last element forms the start of the main chain.
		main.push_back(*(start + (order - 1)));
		// If available, second group forms another main element.
		if (vec.size() >= static_cast<size_t>(2 * order))
			main.push_back(*(start + (order * 2 - 1)));

		// Process the remaining groups.
		// We alternate between pending (pend) groups and main groups.
		for (Iterator it = start + (order * 2); it < end; it += order)
		{
			// First, push the last element of the current group into pend.
			pend.push_back(*(it + (order - 1)));
			it += order;
			if (it < end)
				main.push_back(*(it + (order - 1)));
		}

		// If there is an odd (leftover) group, record its element.
		if (isOdd)
		{
			odd = *(end + (order - 1));
		}

		// Any elements after 'end' that could not form a full group go to left.
		if (std::distance(end, vec.end()) > 0)
			left.insert(left.end(), end, vec.end());

		// Insert the pend chain (and odd element if present) into main.
		insert(main, pend, odd, left, isOdd, vec);
	}
};

// *********************************************************************
//  Main Function
// *********************************************************************
int main(int argc, char *argv[])
{
	// Check for at least one input argument.
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}

	// Process arguments to create a sequence of positive integers.
	// If any argument is not a non-negative integer, print "Error" and exit.
	std::vector<int> vecInput;
	std::deque<int> deqInput;
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num) || num < 0)
		{
			std::cerr << "Error" << std::endl;
			return EXIT_FAILURE;
		}
		vecInput.push_back(num);
		deqInput.push_back(num);
	}

	// Display the unsorted sequence.
	std::cout << "Before: ";
	for (size_t i = 0; i < vecInput.size(); ++i)
		std::cout << vecInput[i] << " ";
	std::cout << std::endl;

	// --- Process and time the std::vector version ---
	PmergeMe<std::vector<int>> sorterVector(vecInput);
	auto startVec = std::chrono::high_resolution_clock::now();
	sorterVector.sort();
	auto endVec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> durationVec = endVec - startVec;

	// --- Process and time the std::deque version ---
	PmergeMe<std::deque<int>> sorterDeque(deqInput);
	auto startDeq = std::chrono::high_resolution_clock::now();
	sorterDeque.sort();
	auto endDeq = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> durationDeq = endDeq - startDeq;

	// Display the sorted sequence (from the vector version).
	std::cout << "After: ";
	const std::vector<int> &sortedVec = sorterVector.getData();
	for (size_t i = 0; i < sortedVec.size(); ++i)
		std::cout << sortedVec[i] << " ";
	std::cout << std::endl;

	// Display timing information.
	std::cout << "Time to process a range of " << vecInput.size()
						<< " elements with std::vector : " << durationVec.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << deqInput.size()
						<< " elements with std::deque  : " << durationDeq.count() << " us" << std::endl;

	return EXIT_SUCCESS;
}
