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
	MonitorModule( const char *title );
	MonitorModule( MonitorModule const & cpy );
	MonitorModule( int width, int height );
	MonitorModule( int width, int height, const char *title );
	virtual	~MonitorModule( void );
	
	virtual void				setHeight( int height );
	virtual int					getHeight( void ) const;
	virtual void				setWidth( int width );
	virtual int					getWidth( void ) const;
	virtual const std::string	getTitle( void ) const;
	virtual void				draw( int posX, int posY, int width, Window const & win ) const;
	virtual void				drawContent( int posX, int posY, int width, int height, Window const & win ) const = 0;

	MonitorModule&		operator=( MonitorModule const & cpy );
private:
	int					_width;
	int					_height;
	const std::string	_title;
};

#include <Window.hpp>

#endif