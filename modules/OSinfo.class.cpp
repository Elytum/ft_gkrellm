/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfo.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:20:35 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 01:31:47 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSinfo.class.hpp"

OSinfo::OSinfo( void )
{
	std::cout << ".Constructor OSinfo called" << std::endl;
	updateInfo();
	printInfo();
}

void	OSinfo::printInfo( void )
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
	std::cout << ".UpdateInfo OSinfo called" << std::endl;
	
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

OSinfo::~OSinfo( void )
{
	std::cout << ".Destructor OSinfo called" << std::endl;
}
