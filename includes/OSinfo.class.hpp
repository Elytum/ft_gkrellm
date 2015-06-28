/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfo.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:21:20 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 02:34:14 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
# define OSINFO_HPP
# include <iostream>
# include <sys/types.h>
# include <sys/sysctl.h>
# include "MonitorModule.hpp"

struct OScontainer
{
	char		model[256];
	char		machine[256];
	int32_t		cputype;
	int32_t		cpufamily;
	int64_t		memsize;
};

class OSinfo : public MonitorModule
{

	public:
		OSinfo(void);
		virtual ~OSinfo(void);

		void	printInfo( void ) const;
		void	updateInfo( void );
		virtual void 	drawContent( int posX, int posY, int width, int height, Window const & win ) const;
	
	private:
		OScontainer _info;
};

#endif /* OSINFO_HPP */

