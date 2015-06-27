#include <MonitorModule.hpp>
#include <Window.hpp>

MonitorModule::MonitorModule( void ) : _height(DEFAULT_HEIGHT), name("")	{
}

MonitorModule::MonitorModule( std::string const & name ) : _height(DEFAULT_HEIGHT), name(name)	{
}

MonitorModule::MonitorModule( MonitorModule const & cpy ) {
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

MonitorModule&		MonitorModule::operator=(MonitorModule const & cpy) {
	_height = cpy.getHeight();
	return *this;
}

void		MonitorModule::draw( int posX, int posY, int width, Window const & win ) const {
	// int y = 0;
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
	// while (y < _height) {
	// 	x = 0;
	// 	while (x < width) {
	// 		win.print(posX + x, posY + y, "m");
	// 		++x;
	// 	}
	// 	++y;
	// }
}