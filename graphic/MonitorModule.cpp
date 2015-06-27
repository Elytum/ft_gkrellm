#include <MonitorModule.hpp>
#include <Window.hpp>

MonitorModule::MonitorModule( void ) : _height(DEFAULT_HEIGHT)	{
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
	int y = 0;
	int x;
	while (y < _height) {
		x = 0;
		while (x < width) {
			win.print(posX + x, posY + y, "m");
			++x;
		}
		++y;
	}
}