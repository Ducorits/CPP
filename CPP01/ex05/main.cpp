/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:25:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/05/01 19:11:54 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>
#include <string>
#include <iostream>

int main()
{
	Harl	karen;

	std::cout << "Welcome to burger extravaganza palace! How may I help you today?" << std::endl;
	karen.complain("DEBUG");
	std::cout << "Okido that'll be $7.50... oh sorry with the extra bacon that'll be... $8.50!" << std::endl;
	karen.complain("INFO");
	std::cout << "Sorry to hear that ma'm. Although that'll still be $8.50." << std::endl;
	karen.complain("WARNING");
	std::cout << "Well ma'm, company policy rules that any extra toppings will be a dollar extra. Nothin' I can do about that." << std::endl;
	karen.complain("ERROR");
	std::cout << "One moment ma'm, I'll call him right away!" << std::endl;
	return 0;
}
