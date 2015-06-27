#ifndef MONITOR_MODULE_HPP
# define MONITOR_MODULE_HPP

#include <IMonitorModule.hpp>
#include <Config.hpp>
#include <iostream>

class Window;

class MonitorModule : public IMonitorModule
{
public:
	MonitorModule( void );
	MonitorModule( const char *name );
	MonitorModule( MonitorModule const & cpy );
	virtual	~MonitorModule( void );
	
	virtual void				setHeight( int height );
	virtual int					getHeight( void ) const;
	virtual const std::string	getTitle( void ) const;
	virtual void				draw( int posX, int posY, int width, Window const & win ) const;

	MonitorModule&		operator=( MonitorModule const & cpy );
private:
	int					_height;
	const std::string	_title;
};

#include <Window.hpp>

#endif