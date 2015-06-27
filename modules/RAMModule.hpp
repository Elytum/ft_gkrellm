#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include <string>
# include <iostream>
# include <../graphic/MonitorModule.hpp>

typedef std::string string;
typedef unsigned int uint;

#include <sys/types.h>
#include <sys/sysctl.h>

#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>


class	RAMModule:public MonitorModule
{
public:
	RAMModule( void );
	RAMModule( RAMModule const& rhs );
	~RAMModule( void );

	RAMModule &	operator=( RAMModule const& rhs );
private:
	void		draw( int x, int y, int w, Window const& );
};

#endif