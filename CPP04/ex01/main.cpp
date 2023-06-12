/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:05:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/02 11:09:56 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>
#include <WrongAnimal.hpp>


int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal* test = new Dog();
	Animal* test2 = new Dog();
	Animal* animals[100];

	for (int i= 0; i < 100; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	static_cast<Cat*>(animals[10])->setBrain( 10, "What do shoes taste like?");
	std::cout << static_cast<Cat*>(animals[10])->getBrain(10) << std::endl;

	static_cast<Dog*>(test2)->setBrain( 10, "What do shoes taste like?");
	std::cout << static_cast<Dog*>(test2)->getBrain(10) << std::endl;

	test = test2;
	delete test2;
	std::cout << static_cast<Dog*>(test)->getBrain(10) << std::endl;



	for (int i = 0; i < 100; i++)
		delete animals[i];
	delete i;
	delete j;
	system("leaks Animals");
	return 0;
}
