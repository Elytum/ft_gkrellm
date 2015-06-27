/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmod.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 01:34:10 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 01:34:49 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef OSINFO_HPP
# define OSINFO_HPP
# include <iostream>
# include <list>
# include <sys/types.h>
# include <sys/sysctl.h>

struct CPUcontainer
{
	char		model[256];
	char		machine[256];
	int32_t		cputype;
	int32_t		cpufamily;
	int64_t		memsize;
};

class CPUmod {

	public:
		CPUmod(void);
		~CPUmod(void);

		void	printInfo( void );
		void	updateInfo( void );
	private:
		CPUcontainer _info;
};

#endif /* OSINFO_HPP */

