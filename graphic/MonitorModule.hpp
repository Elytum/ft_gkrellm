#ifndef MONITOR_MODULE_HPP
# define MONITOR_MODULE_HPP

#include <IMonitorModule.hpp>

enum position {
	TOP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

#define DEFAULT_HEIGHT 8
#define DEFAULT_WIDTH 8

class MonitorModule : public IMonitorModule
{
public:
	MonitorModule( void );
	MonitorModule( MonitorModule const & cpy );
	MonitorModule( MonitorModule const & cpy, position pos );
	virtual	~MonitorModule( void );
	
	virtual void		setColumn( int column );
	virtual void		setLine( int line );
	virtual int			getColumn( void ) const;
	virtual int			getLine( void ) const;
	virtual void		setWidth( int width );
	virtual void		setHeight( int height );
	virtual int			getWidth( void ) const;
	virtual int			getHeight( void ) const;

	MonitorModule&		operator=( MonitorModule const & cpy );
private:
	int		_line;
	int		_column;
	int		_width;
	int		_height;
};

#endif