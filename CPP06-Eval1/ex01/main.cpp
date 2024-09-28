#include <Serializer.hpp>
#include <iostream>
#include <cstdlib>

int	main()
{
	Data	*structure;
	Data	*copy;

	uintptr_t	pointer;

	std::cout << "Made a new Data struct" << std::endl;
	structure = new Data;

	std::cout << "Setting variables in Data" << std::endl;
	structure->charactarrrr = 'a';
	structure->doubly_numbly = 14;
	structure->numnum = 16;

	std::cout << "printing data:" << std::endl;
	std::cout << structure << std::endl;
	std::cout << structure->charactarrrr << std::endl;
	std::cout << structure->doubly_numbly << std::endl;
	std::cout << structure->numnum << std::endl;

	std::cout << "Serializing Data!" << std::endl;
	pointer = Serializer::serialize(structure);

	std::cout << "serialized pointer" << std::endl;
	std::cout << pointer << std::endl;

	std::cout << "deserialize pointer to copy." << std::endl;
	copy = Serializer::deserialize(pointer);

	std::cout << "printing copy data:" << std::endl;
	std::cout << copy << std::endl;
	std::cout << copy->charactarrrr << std::endl;
	std::cout << copy->doubly_numbly << std::endl;
	std::cout << copy->numnum << std::endl;

	delete structure;
}
