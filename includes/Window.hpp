#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <iostream>
# include <list>
# include <vector>
# include <sys/ioctl.h>
# include <unistd.h>
# include <ncurses.h>

# include <ModuleRow.hpp>
# include <MonitorModule.hpp>
# include <Config.hpp>

class ModuleRow;

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
	void		print( int x, int y, char const c ) const;
	void		print( int x, int y, char const *c, char const color ) const;
	void		print( int x, int y, char const c, char const color ) const;
	void		doPrint( int x, int y, char const *c, int color ) const;
	void		printBox(int x, int y, int w, int h) const;
	void		printHLine(int x, int y, int w) const;
	void		flush( void );

	void		addModule( MonitorModule * module, int row );
	void		refresh( void );
	WINDOW*		getWindow( void ) const;

	bool						opened;
	std::vector<ModuleRow>		modules;

	// WINDOW		*window_red;
	// WINDOW		*window_green;
	// WINDOW		*window_blue;
	// WINDOW		*window_yellow;
	WINDOW		*window_white;
	// WINDOW		*window_magenta;
	// WINDOW		*window_cyan;
	// WINDOW		*window_reverse_red;
	// WINDOW		*window_reverse_green;
	// WINDOW		*window_reverse_blue;
	// WINDOW		*window_reverse_yellow;
	// WINDOW		*window_reverse_white;
	// WINDOW		*window_reverse_magenta;
	// WINDOW		*window_reverse_cyan;
	WINDOW		*main_window;
	int			height;
	int			width;
	
};

#endif