/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/23 21:25:37 by dritsema      #+#    #+#                 */
/*   Updated: 2023/04/29 15:57:43 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		str;
	int				index;
	size_t			i;

	if (argc == 4)
	{
		infile.open(argv[1]);
		str = argv[1];
		outfile.open(str + ".replace", std::ios::out | std::ios::trunc);
		if (!infile.is_open() || !infile.good() || !outfile.is_open() || !outfile.good())
		{
			std::cout << "Failed to open or create file(s)." << std::endl;
			return (1);
		}
		while (std::getline(infile, str))
		{
			index = str.find(argv[2]);
			if (index != -1)
			{
				i = 0;
				while (i < str.length())
				{
					if (str.compare(i, std::strlen(argv[2]), argv[2]) == 0)
					{
						outfile << argv[3];
						i += std::strlen(argv[2]);
						continue;
					}
					else
						outfile << str[i];
					i++;
				}
			}
			else
				outfile << str;
			outfile << std::endl;
		}
		infile.close();
		outfile.close();
	}
	else
		std::cout << "Invalid argument count. Usage:./replace-otron <filename> <string to replace> <replacement string>" << std::endl;
	return (0);
}
