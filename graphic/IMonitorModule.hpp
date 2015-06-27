#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

class IMonitorModule
{
public:
	virtual	~IMonitorModule( void ) {}
	virtual void	setColumn( int column ) = 0;
	virtual void	setLine( int line ) = 0;
	virtual int		getColumn( void ) const = 0;
	virtual int		getLine( void ) const = 0;
	virtual void	setWidth( int width ) = 0;
	virtual void	setHeight( int height ) = 0;
	virtual int		getWidth( void ) const = 0;
	virtual int		getHeight( void ) const = 0;
};

#endif