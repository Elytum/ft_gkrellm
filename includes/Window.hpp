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

# define COLOR_ORANGE 101
# define COLOR_VIOLET 102
# define COLOR_GREY   103

class ModuleRow;

enum colorsKind {
	BLACK = 1,
	RED = 1,
	GREEN = 2,
	BLUE = 3,
	YELLOW = 4,
	WHITE = 5,
	MAGENTA = 6,
	CYAN = 7,
	REVERSE_RED = 8,
	REVERSE_GREEN = 9,
	REVERSE_BLUE = 10,
	REVERSE_YELLOW = 11,
	REVERSE_WHITE = 12,
	REVERSE_MAGENTA = 13,
	REVERSE_CYAN = 14,

	ORANGE = 15,
	REVERSE_ORANGE = 16,

	VIOLET = 17,
	REVERSE_VIOLET = 18,

	GREY = 19,
	REVERSE_GREY = 20, 
};

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
	void		doPrint( int x, int y, char const *c, colorsKind color ) const;
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