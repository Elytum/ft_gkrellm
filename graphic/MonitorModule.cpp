#include <MonitorModule.hpp>
#include <Window.hpp>

MonitorModule::MonitorModule( void ) : _line(MAX_HEIGHT_MODULES + 1),
	_column(MAX_WIDTH_MODULES + 1), _width(DEFAULT_WIDTH), _height(DEFAULT_HEIGHT)	{
}

MonitorModule::MonitorModule( MonitorModule const & cpy ) {
	*this = cpy;
}

MonitorModule::MonitorModule( MonitorModule const & cpy, position pos ) {
	*this = cpy;
	if (pos == TOP)
		_line--;
	else if (pos == DOWN)
		_line++;
	else if (pos == LEFT)
		_column--;
	else if (pos == RIGHT)
		_column++;
}

MonitorModule::~MonitorModule( void ) {
}

void	MonitorModule::setColumn( int column ) {
	_column = column;
}

void	MonitorModule::setLine( int line ) {
	_line = line;
}

int		MonitorModule::getColumn( void ) const {
	return _column;
}

int		MonitorModule::getLine( void ) const {
	return _line;
}

void	MonitorModule::setWidth( int width ) {
	_width = width;
}

void	MonitorModule::setHeight( int height ) {
	_height = height;
}

int		MonitorModule::getWidth( void ) const {
	return _width;
}

int		MonitorModule::getHeight( void ) const {
	return _height;
}

MonitorModule&		MonitorModule::operator=(MonitorModule const & cpy) {
	_line = cpy.getLine();
	_column = cpy.getColumn();
	_width = cpy.getWidth();
	_height = cpy.getHeight();
	return *this;
}