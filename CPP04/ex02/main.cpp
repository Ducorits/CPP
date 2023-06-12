/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 18:05:40 by dritsema      #+#    #+#                 */
/*   Updated: 2023/06/12 18:18:19 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <A_Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>
#include <WrongAnimal.hpp>


int	main(void)
{
	const A_Animal* j = new Dog();
	const A_Animal* i = new Cat();
	A_Animal* animals[100];

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

	static_cast<Cat*>(animals[10])->setBrain( 10, "What do shoes taste like?");
	std::cout << static_cast<Cat*>(animals[10])->getBrain(10) << std::endl;

	for (int i = 0; i < 100; i++)
		delete animals[i];
	delete i;
	delete j;
	system("leaks Animals");
	return 0;
}
