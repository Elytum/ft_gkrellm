#include <Window.hpp>

Window::Window() : opened(false),
	window_white(NULL), main_window(NULL) {
		modules.resize(MAX_WIDTH_MODULES);
}

Window::~Window() {
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

	window_white = derwin(main_window, w.ws_row, w.ws_col, 0, 0);

	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);
	init_pair(12, COLOR_BLACK, COLOR_WHITE);
	init_pair(13, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(14, COLOR_BLACK, COLOR_CYAN);


	// init_color(COLOR_RED, 500, 500, 500);

	// wbkgd(window_white, COLOR_PAIR(5));

	noecho();
	curs_set(FALSE);
	nodelay(main_window, TRUE);
}

void				Window::close( void )	{
	if (opened == false)
		return ;
	endwin();
}

void		Window::clr( void ) const {
	werase(main_window);
}

void		Window::print( int x, int y, char const *c ) const {
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	doPrint(x, y, c, 0);
}

void		Window::print( int x, int y, char const c ) const {
	static char tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	doPrint(x, y, tmp, 1);
}

void		Window::doPrint(int x, int y, const char *str, int color) const {
	wattron(main_window, COLOR_PAIR(color));
	mvwprintw(main_window, y, x, str);
	wattroff(main_window, COLOR_PAIR(color));
}

void		Window::print( int x, int y, char const *c, char const color ) const {
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (color == 'R')
		doPrint(x, y, c, 1);
	else if (color == 'G')
		doPrint(x, y, c, 2);
	else if (color == 'B')
		doPrint(x, y, c, 3);
	else if (color == 'Y')
		doPrint(x, y, c, 4);
	else if (color == 'W')
		doPrint(x, y, c, 5);
	else if (color == 'M')
		doPrint(x, y, c, 6);
	else if (color == 'C')
		doPrint(x, y, c, 7);
	else if (color == 'r')
		doPrint(x, y, c, 8);
	else if (color == 'g')
		doPrint(x, y, c, 9);
	else if (color == 'b')
		doPrint(x, y, c, 10);
	else if (color == 'y')
		doPrint(x, y, c, 11);
	else if (color == 'w')
		doPrint(x, y, c, 12);
	else if (color == 'm')
		doPrint(x, y, c, 13);
	else if (color == 'c')
		doPrint(x, y, c, 14);
}

void		Window::print( int x, int y, char const c, char const color ) const {
	static char tmp[2] = {'\0'};

	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	tmp[0] = c;
	tmp[1] = '\0';
	if (color == 'R')
		doPrint(x, y, tmp, 1);
	else if (color == 'G')
		doPrint(x, y, tmp, 2);
	else if (color == 'B')
		doPrint(x, y, tmp, 3);
	else if (color == 'Y')
		doPrint(x, y, tmp, 4);
	else if (color == 'W')
		doPrint(x, y, tmp, 5);
	else if (color == 'M')
		doPrint(x, y, tmp, 6);
	else if (color == 'C')
		doPrint(x, y, tmp, 7);
	else if (color == 'r')
		doPrint(x, y, tmp, 8);
	else if (color == 'g')
		doPrint(x, y, tmp, 9);
	else if (color == 'b')
		doPrint(x, y, tmp, 10);
	else if (color == 'y')
		doPrint(x, y, tmp, 11);
	else if (color == 'w')
		doPrint(x, y, tmp, 12);
	else if (color == 'm')
		doPrint(x, y, tmp, 13);
	else if (color == 'c')
		doPrint(x, y, tmp, 14);
}

void		Window::printBox(int x, int y, int w, int h) const {
	mvwaddch(window_white, y, x, ACS_PLUS);
	mvwaddch(window_white, y, x + w, ACS_PLUS);
	mvwaddch(window_white, y + h, x, ACS_PLUS);
	mvwaddch(window_white, y + h, x + w, ACS_PLUS);
	mvwhline(window_white, y, x + 1, ACS_HLINE, w - 1);
	mvwhline(window_white, y + h, x + 1, ACS_HLINE, w - 1);
	mvwvline(window_white, y + 1, x, '|', h - 1);
	mvwvline(window_white, y + 1, x + w, '|', h - 1);
	// (void)x;
	// (void)y;
	// (void)w;
	// (void)h;
}

void		Window::printHLine(int x, int y, int w) const
{
	mvwaddch(window_white, y, x, ACS_PLUS);
	mvwaddch(window_white, y, x + w, ACS_PLUS);
	mvwhline(window_white, y, x + 1, ACS_HLINE, w - 1);
	// (void)x;
	// (void)y;
	// (void)w;
};

void	Window::flush( void )	{
	touchwin(main_window);
	wrefresh(main_window);
}

void		Window::addModule( MonitorModule * module, int row ) {
	modules[row].addModule(module);
}

void		Window::refresh( void ) {
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
























