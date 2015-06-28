/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmod.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 01:32:53 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 09:10:44 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "CPUmod.class.hpp"
#include <stdio.h>
#include <string>
#include <vector>
#include "MonitorModule.hpp"

#include <iostream>

CPUmod::CPUmod( void ) : MonitorModule(45, 10, "CPUmod")
{
	//procInfo();
	updateInfo();
	//printInfo();
}

void	CPUmod::printInfo( void )
{/*
	std::vector<std::string>::const_iterator 	it;
	std::vector<std::string>::const_iterator 	ite = _info.cpu.end();

	for (it = _info.cpu.begin(); it != ite; ++it)
	{
		std::cout << *it << std::endl;
	}
*/}

void	CPUmod::procInfo( void )
{/*
	FILE *in;
	char buff[512];

	if(!(in = popen("top -l1 -n0", "r"))){
		//std::cout << "error" << std::endl;
	}
	while(fgets(buff, sizeof(buff), in)!=NULL){
		_info.cpu.push_back(std::string(buff));
	}
	pclose(in);
*/
}
template< typename T >
void	printType( int posX, int posY, int width, int height, Window const &win, char const *s, T index)
{
	win.print(posX + 1, posY, s);
	win.print(posX + 1 + strlen(s), posY, index);
	width = height = 0;
}

void 	CPUmod::updateInfo( void )
{	
	size_t	brand = sizeof(_info.brand);
	
	sysctlbyname("machdep.cpu.brand_string", &_info.brand, &brand, NULL, 0);
}

void	CPUmod::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	printType(posX, posY, width, height, win, "", _info.brand);
}

CPUmod::~CPUmod( void )
{
}
