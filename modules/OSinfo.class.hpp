/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfo.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:21:20 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 01:03:33 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
# define OSINFO_HPP
# include <iostream>
# include <list>
# include <sys/types.h>
# include <sys/sysctl.h>

struct OScontainer
{
	char		model[256];
	char		machine[256];
	int32_t		cputype;
	int32_t		cpufamily;
	int64_t		memsize;
};

class OSinfo {

	public:
		OSinfo(void);
		~OSinfo(void);

		void	printInfo( void );
		void	updateInfo( void );
	private:
		OScontainer _info;
};

#endif /* OSINFO_HPP */

