#include <Window.hpp>

Window::Window() : opened(false), modules(new MonitorModule*[MAX_HEIGHT_MODULES]),
	window_red(NULL), window_green(NULL), window_blue(NULL),
	window_yellow(NULL), window_white(NULL), main_window(NULL) {
	for (int i = 0; i < MAX_HEIGHT_MODULES; ++i)
		modules[i] = new MonitorModule[MAX_WIDTH_MODULES];
}

Window::~Window() {
	for (int i = 0; i < MAX_HEIGHT_MODULES; ++i)
		delete [] modules[i];
	delete [] modules;
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
	std::cout << "x: " << x << ", y: " << y << ", c: '" << c << "', width: " << width << ", height: " << height << std::endl;
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

void		Window::addModule( MonitorModule & module ) {
	int line = module.getLine();
	int column = module.getColumn();

	if (line < 0) {
		module.setLine(0);
		line = 0;
	}
	else if (line >= MAX_HEIGHT_MODULES) {
		module.setLine(MAX_HEIGHT_MODULES - 1);
		line = MAX_HEIGHT_MODULES - 1;
	}
	if (column < 0) {
		module.setColumn(0);
		column = 0;
	}
	else if (column >= MAX_WIDTH_MODULES) {
		module.setColumn(MAX_WIDTH_MODULES - 1);
		column = MAX_WIDTH_MODULES - 1;
	}
	modules[line][column] = module;
}

void		Window::drawModule( MonitorModule & module ) {
	int width = module.getWidth();
	int height = module.getHeight();

	int y = 0;
	int x;
	while (y < height) {
		x = 0;
		while (x < width) {
			print(x, y, "m");
			++x;
		}
		++y;
	}
}



























