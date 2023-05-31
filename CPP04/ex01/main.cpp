/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:05:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/31 17:20:45 by dritsema      ########   odam.nl         */
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
	const WrongAnimal* a = new WrongCat();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
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
	std::cout << a->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	a->makeSound();
	meta->makeSound();

	for (int i = 0; i < 100; i++)
		delete animals[i];
	delete i;
	delete j;
	delete a;
	return 0;
}
