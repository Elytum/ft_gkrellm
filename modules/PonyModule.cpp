// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PonyModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hmoutaou <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/28 10:04:59 by hmoutaou          #+#    #+#             //
//   Updated: 2015/06/28 10:05:00 by hmoutaou         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PonyModule.hpp"

#define REQUIRED_WIDTH 25
#define REQUIRED_HEIGHT 10

PonyModule::PonyModule( void ): MonitorModule(REQUIRED_WIDTH, REQUIRED_HEIGHT, "Run pony !! Run !!") {

}

PonyModule::PonyModule( PonyModule const& rhs )
{
	*this = rhs;
}

PonyModule::~PonyModule( void ) {}

PonyModule &	PonyModule::operator=( PonyModule const& )
{
	return (*this);
}

void		PonyModule::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	(void)width;
	(void)height;


	static int		gallop_count = -1;
	static int		gallop_tick = 1255;

	const char			*gallop[8][7];

	gallop[0][0] = "                   ";
	gallop[0][1] = "               ,~  ";
	gallop[0][2] = "            ~~/(\\ ";
	gallop[0][3] = "  ~~ _____~~/ / `  ";
	gallop[0][4] = "~~~~( )___( /      ";
	gallop[0][5] = "   /|/_  _`/|      ";
	gallop[0][6] = "     \\    /       ";

	gallop[1][0] = "                   ";
	gallop[1][1] = "               ,~  ";
	gallop[1][2] = "            ~~/(\\ ";
	gallop[1][3] = "  ~~ _____~~/ / `  ";
	gallop[1][4] = "~~~~( )___( /      ";
	gallop[1][5] = "    |\\_  _`/|     ";
	gallop[1][6] = "     `    '        ";

	gallop[2][0] = "                   ";
	gallop[2][1] = "               ,~  ";
	gallop[2][2] = "            ~~/(\\ ";
	gallop[2][3] = "   ~ _____~~/ / `  ";
	gallop[2][4] = "~~~~( )___( /      ";
	gallop[2][5] = "    |\\_   `/|     ";
	gallop[2][6] = "     `    //       ";

	gallop[3][0] = "                   ";
	gallop[3][1] = "              ,~   ";
	gallop[3][2] = "            ~/(\\  ";
	gallop[3][3] = "   ~ _____~/ / `   ";
	gallop[3][4] = " ~~~( )___( |      ";
	gallop[3][5] = "    |\\     ` \\   ";
	gallop[3][6] = "     `\\    '/     ";

	gallop[4][0] = "                   ";
	gallop[4][1] = "              ,~   ";
	gallop[4][2] = "            ~/(\\  ";
	gallop[4][3] = "   ~ _____~/ / `   ";
	gallop[4][4] = "~~~~( )___(_|_     ";
	gallop[4][5] = "     \\     _\\/   ";
	gallop[4][6] = "     `\\           ";

	gallop[5][0] = "                   ";
	gallop[5][1] = "              ,~   ";
	gallop[5][2] = "            ~/(\\  ";
	gallop[5][3] = "   ~ _____~/ / `   ";
	gallop[5][4] = " ~~~( )___(_|_     ";
	gallop[5][5] = "   ///     _\\/    ";
	gallop[5][6] = "   ` \\            ";

	gallop[6][0] = "                   ";
	gallop[6][1] = "              ,~   ";
	gallop[6][2] = "            ~/(\\  ";
	gallop[6][3] = "   ~ _____~/ / `   ";
	gallop[6][4] = " ~~~( )___(_|_     ";
	gallop[6][5] = "   / /     _\\ \\  ";
	gallop[6][6] = "  //               ";

	gallop[7][0] = "                   ";
	gallop[7][1] = "              ,~   ";
	gallop[7][2] = "            ~/(\\  ";
	gallop[7][3] = "   ~ _____~/ / `   ";
	gallop[7][4] = " ~~~( )___(_|_     ";
	gallop[7][5] = "   /|/_      \\ \\ ";
	gallop[7][6] = "   `          \\   ";


	gallop_tick = gallop_tick + 1;
	if (gallop_tick >= 1256)
	{
		gallop_tick = 0;

		gallop_count = gallop_count + 1;
		if (gallop_count >= 8)
		{
			gallop_count = 0;
		}
	}

	win.print(posX + (width - 19) / 2, posY + 0, gallop[gallop_count][0]);
	win.print(posX + (width - 19) / 2, posY + 1, gallop[gallop_count][1]);
	win.print(posX + (width - 19) / 2, posY + 2, gallop[gallop_count][2]);
	win.print(posX + (width - 19) / 2, posY + 3, gallop[gallop_count][3]);
	win.print(posX + (width - 19) / 2, posY + 4, gallop[gallop_count][4]);
	win.print(posX + (width - 19) / 2, posY + 5, gallop[gallop_count][5]);
	win.print(posX + (width - 19) / 2, posY + 6, gallop[gallop_count][6]);

};

