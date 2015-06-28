// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hmoutaou <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/28 00:51:18 by hmoutaou          #+#    #+#             //
/*   Updated: 2015/06/28 03:19:52 by bwanlin          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "TimeModule.hpp"

#define REQUIRED_WIDTH 22
#define REQUIRED_HEIGHT 4

TimeModule::TimeModule( void ): MonitorModule(REQUIRED_WIDTH, REQUIRED_HEIGHT, "Time & Date") {

}

TimeModule::TimeModule( TimeModule const& rhs )
{
	*this = rhs;
}

TimeModule::~TimeModule( void ) {}

TimeModule &	TimeModule::operator=( TimeModule const& )
{
	return (*this);
}

void		TimeModule::drawContent( int posX, int posY, int width, int height, Window const & win ) const
{
	 if (width < REQUIRED_WIDTH - 3 || height < REQUIRED_HEIGHT - 3)
	 {
	 	return ;
	 }

	std::time_t t = std::time(0); 

    struct tm * dt;
    char buffer [30];
    dt = localtime(&t);
    strftime(buffer, sizeof(buffer), " %H:%M:%S %d/%m/%Y", dt);
	
	win.print(posX + (width - strlen(buffer)) / 2, posY, buffer);
}
