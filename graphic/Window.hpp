#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <iostream>
# include <list>
# include <vector>
# include <sys/ioctl.h>
# include <unistd.h>
# include <ncurses.h>

# include <ModuleRaw.hpp>
# include <MonitorModule.hpp>
# include <Config.hpp>

class ModuleRaw;

class Window
{
public:
	Window();
	~Window();

	int			getSeenWidth();
	int			getSeenHeight();
	void		open( void );
	void		close( void );
	void		clr( void ) const;
	void		print( int x, int y, char const *c ) const;
	void		print( int x, int y, char const *c, char const color ) const;
	void		print( int x, int y, char const c, char const color ) const;
	void		flush( void );

	void		addModule( MonitorModule & module, int raw );
	void		refresh( void ) const;
	WINDOW*		getWindow( void ) const;

	bool					opened;
	std::vector<ModuleRaw>	modules;

	WINDOW		*window_red;
	WINDOW		*window_green;
	WINDOW		*window_blue;
	WINDOW		*window_yellow;
	WINDOW		*window_white;
	WINDOW		*main_window;
	int			height;
	int			width;
	
};

#endif