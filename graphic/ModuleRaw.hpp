#ifndef MODULERAW_HPP
# define MODULERAW_HPP

#include <MonitorModule.hpp>
#include <Config.hpp>

#include <iostream>
#include <Vector>

class ModuleRaw
{
public:
	ModuleRaw( void );
	~ModuleRaw( void );
	void								addModule( MonitorModule & mod );
	const std::vector<MonitorModule>	getModules( void ) const;
	int									getWidth( void ) const;
	MonitorModule&						operator[]( int pos );
	void								draw( int x, int y, Window const & win ) const;
private:
	int							width;
	std::vector<MonitorModule>	modules;
};

#include <Window.hpp>

#endif
