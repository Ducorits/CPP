#include <iostream>

void PmergeMe(char **argv)
{
	(void)argv;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	else
	{
		PmergeMe(argv);
	}
}