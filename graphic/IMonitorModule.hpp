#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

class IMonitorModule
{
public:
	virtual	~IMonitorModule( void ) {}
	virtual void	setHeight( int height ) = 0;
	virtual int		getHeight( void ) const = 0;
};

#endif