#include <Window.hpp>

Window::Window() : opened(false),
	window_red(NULL), window_green(NULL), window_blue(NULL),
	window_yellow(NULL), window_white(NULL), main_window(NULL) {
		modules.resize(MAX_WIDTH_MODULES);
}

Window::~Window() {
	if (window_red)
		delwin(window_red);
	if (window_green)
		delwin(window_green);
	if (window_blue)
		delwin(window_blue);
	if (window_yellow)
		delwin(window_yellow);
	if (window_white)
		delwin(window_white);
	if (main_window)
		delwin(main_window);
}

int			Window::getSeenWidth() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return (w.ws_col);
}

int			Window::getSeenHeight() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return (w.ws_row);
}

void	Window::open( void ) {
	if (opened == true)
		return ;
	opened = true;
	initscr();

	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	main_window = newwin(w.ws_row, w.ws_col, 0, 0);
	keypad(main_window, TRUE);

	window_red = derwin(main_window, w.ws_row, w.ws_col, 0, 0);
	window_green = derwin(main_window, w.ws_row, w.ws_col, 0, 0);
	window_blue = derwin(main_window, w.ws_row, w.ws_col, 0, 0);
	window_yellow = derwin(main_window, w.ws_row, w.ws_col, 0, 0);
	window_white = derwin(main_window, w.ws_row, w.ws_col, 0, 0);

	init_color(COLOR_RED, 500, 500, 500);
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);

	wbkgd(window_red, COLOR_PAIR(1));
	wbkgd(window_green, COLOR_PAIR(2));
	wbkgd(window_blue, COLOR_PAIR(3));
	wbkgd(window_yellow, COLOR_PAIR(4));
	wbkgd(window_white, COLOR_PAIR(5));

	noecho();
	curs_set(FALSE);
}

void				Window::close( void )	{
	if (opened == false)
		return ;
	endwin();
}

void	Window::clr( void ) const {

	werase(main_window);
}

void		Window::print( int x, int y, char const *c ) const {
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	mvwprintw(main_window, y, x, c);
}

void		Window::print( int x, int y, char const *c, char const color ) const {
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (color == 'R')
		mvwprintw(window_red, y, x, c);
	else if (color == 'G')
		mvwprintw(window_green, y, x, c);
	else if (color == 'B')
		mvwprintw(window_blue, y, x, c);
	else if (color == 'Y')
		mvwprintw(window_yellow, y, x, c);
	else if (color == 'W')
		mvwprintw(window_white, y, x, c);
}

void		Window::print( int x, int y, char const c, char const color ) const {
	static char tmp[2] = {'\0'};

	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	tmp[0] = c;
	if (color == 'R')
		mvwprintw(window_red, y, x, tmp);
	else if (color == 'G')
		mvwprintw(window_green, y, x, tmp);
	else if (color == 'B')
		mvwprintw(window_blue, y, x, tmp);
	else if (color == 'Y')
		mvwprintw(window_yellow, y, x, tmp);
	else if (color == 'W')
		mvwprintw(window_white, y, x, tmp);
}

void	Window::flush( void )	{
	wrefresh(main_window);
}

void		Window::addModule( MonitorModule & module, int raw ) {
	modules[raw].addModule(module);
}

void		Window::refresh( void ) const {
	int	i = modules.size();
	int p = 0;
	int posX = 0;

	while (p < i) {
		modules[p].draw(posX, 0, *this);
		posX += modules[p].getWidth();
		++p;
	}
}

WINDOW*		Window::getWindow( void ) const {
	return main_window;
}
























