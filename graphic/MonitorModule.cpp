#include <MonitorModule.hpp>
#include <Window.hpp>
#include <string.h>

MonitorModule::MonitorModule( void ) : _height(DEFAULT_HEIGHT), _title("")	{
}

MonitorModule::MonitorModule( const char *name ) : _height(DEFAULT_HEIGHT), _title(name)	{
}

MonitorModule::MonitorModule( MonitorModule const & cpy ) : _title(cpy.getTitle()) {
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

	// int x;

	// win.print(posX, posY, "/");
	// win.print(posX + width, posY, "\\");
	// win.print(posX, posY + _height, "\\");
	// win.print(posX + width, posY + _height, "/");

	for (int x = 0; x < width; ++x) {
		win.print(posX + x, posY, "_");
		win.print(posX + x, posY + _height, "_");
	}
	for (int y = 1; y < _height; ++y) {
		win.print(posX, posY + y, "|");
		win.print(posX + _height, posY + y, "|");
	}

	int diff = width - 2 - _title.size();
	if (diff > 0) {
		// int before = diff / 2;
		// int after = diff - before;

		// memset(tmp, ' ', before);
		// memcpy(tmp + before, _title.c_str(), _title.size());
		// memset(tmp + before + _title.size(), ' ', after);
		// tmp[before + _title.size() + after] = '\0';
		win.print(posX + 1 + diff / 2, posY + 1, _title.c_str());
	} else if (diff == 0)
		win.print(posX + 1, posY + 1, _title.c_str());
	else {
		memcpy(tmp, _title.c_str(), bufSize);
		if (bufSize >= 2 && width - 2 < bufSize) {
			tmp[width - 2] = '.';
			tmp[width - 1] = '\0';
			win.print(posX + 1, posY + 1, tmp);
		}
	}
	// win.print(posX + 1, posY + 1, tmp);
	// win.print(20, 20, _name);
	// (void)_name;
	(void)_title;
	// while (y < _height) {
	// 	x = 0;
	// 	while (x < width) {
	// 		win.print(posX + x, posY + y, "m");
	// 		++x;
	// 	}
	// 	++y;
	// }
}