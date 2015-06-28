/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmod.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 01:34:10 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 09:02:31 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CPUMOD_HPP
# define CPUMOD_HPP
# include <iostream>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <vector>
# include "MonitorModule.hpp"
# include "Window.hpp"
struct CPUcontainer
{
	char	brand[256];
};

class CPUmod : public MonitorModule
{

	public:
		CPUmod(void);
		virtual ~CPUmod(void);

		void	printInfo( void );
		void	updateInfo( void );
		void	procInfo( void );

		virtual void	drawContent( int posX, int posY, int width, int height, Window const & win );

	private:
		CPUcontainer	_info;
};

#endif /* OSINFO_HPP */

