/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/29 16:03:53 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/01 19:27:41 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>
#include <iostream>

void Harl::debug( void )
{
	std::cout << "I would like a 7XL-double-cheese-triple-pickle-specialketchup burger with extra bacon and a big heaving diet coke!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "What?! a dollar extra for bacon?! I cannot believe adding extra bacon costs that much! You never put enough bacon on the burgers! If it was enough, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout <<"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now!!" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string	message[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	i = 0;
	while (i < 4)
	{
		if (level == message[i])
		{
			break;
		}
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			Harl::debug();
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			Harl::info();
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			Harl::warning();
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			Harl::error();
			std::cout << std::endl;
	}
	if (i == 4)
		std::cout << "[ Probably spouting on about some insignificant little problem... ]" << std::endl;
}
