/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfo.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:20:35 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 03:13:19 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSinfo.class.hpp"
#include <string>
OSinfo::OSinfo( void ) : MonitorModule(45, 8, "OSinfo")
{
	updateInfo();
}

void	OSinfo::printInfo( void ) const
{
	std::cout << ".Retrieving Data from OSinfo" << std::endl;
	std::cout << "hw.model: " << _info.model << std::endl;
	std::cout << "hw.machine: " << _info.machine << std::endl;
	std::cout << "hw.cputype: " << _info.cputype << std::endl;
	std::cout << "hw.cpufamily: " << _info.cpufamily << std::endl;
	std::cout << "hw.memsize: " << _info.memsize << std::endl;
}

void OSinfo::updateInfo( void )
{
	
	size_t	model = sizeof(_info.model);
	size_t	machine = sizeof(_info.machine);
	size_t	cputype = sizeof(_info.cputype);
	size_t	cpufamily = sizeof(_info.cpufamily);
	size_t	memsize = sizeof(_info.memsize);

	sysctlbyname("hw.model", &_info.model, &model, NULL, 0);
	sysctlbyname("hw.machine", &_info.machine, &machine, NULL, 0);
	sysctlbyname("hw.cputype", &_info.cputype, &cputype, NULL, 0);
	sysctlbyname("hw.cpufamily", &_info.cpufamily, &cpufamily, NULL, 0);	
	sysctlbyname("hw.memsize", &_info.memsize, &memsize, NULL, 0);
}

template< typename T >
void	printType( int posX, int posY, int width, int height, Window const &win, char const *s, T index)
{
	win.print(posX + 1, posY, s);
	win.print(posX + 1 + strlen(s), posY, index);
	width = height = 0;
}

void	OSinfo::drawContent( int posX, int posY, int width, int height, Window const & win ) const
{
	printType(posX, posY, width, height, win, "hw.model: ", _info.model);
	posY++;	
	printType(posX, posY, width, height, win, "hw.machine: ", _info.machine);
	posY++;
	printType(posX, posY, width, height, win, "hw.cputype: ", (std::to_string(_info.cputype)).c_str());
	posY++;	
	printType(posX, posY, width, height, win, "hw.cpufamily: ", (std::to_string(_info.cpufamily)).c_str());
	posY++;
	printType(posX, posY, width, height, win, "hw.memsize: ", (std::to_string(_info.memsize)).c_str());
	posY++;

}

OSinfo::~OSinfo( void )
{
}
