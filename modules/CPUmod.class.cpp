/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmod.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 01:32:53 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 01:59:30 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "CPUmod.class.hpp"

CPUmod::CPUmod( void )
{
	std::cout << ".Constructor CPUmod called" << std::endl;
	updateInfo();
	printInfo();
}

void	CPUmod::printInfo( void )
{
	std::cout << ".Retrieving Data from CPUmod" << std::endl;
	std::cout << "hw.model: " << _info.model << std::endl;
	std::cout << "hw.machine: " << _info.machine << std::endl;
	std::cout << "hw.cputype: " << _info.cputype << std::endl;
	std::cout << "hw.cpufamily: " << _info.cpufamily << std::endl;
	std::cout << "hw.memsize: " << _info.memsize << std::endl;
}

void CPUmod::updateInfo( void )
{
	std::cout << ".UpdateInfo CPUmod called" << std::endl;
	
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

CPUmod::~CPUmod( void )
{
	std::cout << ".Destructor CPUmod called" << std::endl;
}
