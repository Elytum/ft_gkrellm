#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <iostream>
# include <list>
# include <sys/ioctl.h>
# include <unistd.h>

# include <MonitorModule.hpp>
# include <ncurses.h>

#define MAX_WIDTH_MODULES 50
#define MAX_HEIGHT_MODULES 50

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

	void		addModule( MonitorModule & module );
	void		drawModule( MonitorModule & module );

	bool				opened;
	MonitorModule		**modules;
	WINDOW				*window_red;
	WINDOW				*window_green;
	WINDOW				*window_blue;
	WINDOW				*window_yellow;
	WINDOW				*window_white;
	WINDOW				*main_window;
	int					height;
	int					width;
	
};

#endif