#include <MonitorModule.hpp>
#include <Window.hpp>
#include <string.h>

MonitorModule::MonitorModule( void ) : _height(DEFAULT_HEIGHT), _title("")	{
}

MonitorModule::MonitorModule( std::string title ) : _height(DEFAULT_HEIGHT), _title(title)	{
}

MonitorModule::MonitorModule( MonitorModule const & cpy ) : _title(cpy._title) {
	*this = cpy;
}

MonitorModule::~MonitorModule( void ) {
}

void	MonitorModule::setHeight( int height ) {
	_height = height;
}

int		MonitorModule::getHeight( void ) const {
	return _height;
}

const std::string MonitorModule::getTitle( void ) const {
	return _title;
}

MonitorModule&		MonitorModule::operator=(MonitorModule const & cpy) {
	_height = cpy.getHeight();
	return *this;
}

void		MonitorModule::draw( int posX, int posY, int width, Window const & win ) const {
	const int	bufSize = 1024;
	static char	tmp[bufSize];

	for (int x = 0; x < width; ++x) {
		win.print(posX + x, posY, "_");
		win.print(posX + x, posY + _height, "_");
	}
	for (int y = 1; y < _height; ++y) {
		win.print(posX, posY + y, "|");
		win.print(posX + _height, posY + y, "|");
	}

	if (_title.size()) {
		for (int x = 0; x < width; ++x)
			win.print(posX + x, posY + 2, "-");
		int diff = width - 2 - _title.size();
		if (diff > 0) {
			win.print(posX + 1 + diff / 2, posY + 1, _title.c_str());
			drawContent(posX + 1, posY + 3, width - 2, _height - 2, win);
		}
		else if (diff == 0) {
			win.print(posX + 1, posY + 1, _title.c_str());
			drawContent(posX + 1, posY + 3, width - 2, _height - 2, win);
		}
		else if (bufSize >= 2 && width - 2 < bufSize) {
				memcpy(tmp, _title.c_str(), bufSize);
				tmp[width - 2] = '.';
				tmp[width - 1] = '\0';
				win.print(posX + 1, posY + 1, tmp);
				drawContent(posX + 1, posY + 1, width - 2, _height - 2, win);
		}
	}
	else
		drawContent(posX + 1, posY + 1, width - 2, _height - 2, win);
}
