/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:25:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/01 19:24:46 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	Harl		karen;
	std::string	complaint;

	if (argc == 2)
	{
		karen.complain(argv[1]);
	}
	else
		std::cout << "Incorrect argument count!" << std::endl;

	return 0;
}
