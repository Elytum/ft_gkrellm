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
#include "../includes/CPUmod.class.hpp"
#include <stdio.h>
#include <string>
#include <vector>
#include "../includes/MonitorModule.hpp"

#include <iostream>

CPUmod::CPUmod( void ) : MonitorModule(19, 6, "CPUmod")
{
	//procInfo();
	updateInfo();
	//printInfo();
}
CPUmod::CPUmod( std::string str ) : MonitorModule(19, 6, str)
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

void	printType( int posX, int posY, int width, Window const &win, std::string str)
{
	win.print(posX + (width - str.size()) / 2 , posY, str.c_str());
}

void 	CPUmod::updateInfo( void )
{	
	size_t	brand = sizeof(_info.brand);
	
	sysctlbyname("machdep.cpu.brand_string", &_info.brand, &brand, NULL, 0);
}

void	CPUmod::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	std::stringstream str;

	str << _info.brand;
	std::string brand;
	std::string core;
	std::string name;
	std::string cpu;
	std::string speed;

	str >> brand;
	str >> core;
	str >> name;
	str >> cpu;
	str >> speed;
	str >> speed;
	(void)height;
	int offset = (height - 4) / 2;
	printType(posX, posY + 0 + offset, width, win, brand + core);
	printType(posX, posY + 1 + offset, width, win, name + cpu);
	printType(posX, posY + 2 + offset, width, win, speed);
}

CPUmod::~CPUmod( void )
{
}
