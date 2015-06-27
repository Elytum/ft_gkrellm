#include <FooBar.hpp>

FooBar::FooBar( void ) : MonitorModule("FooBar") {
}

FooBar::FooBar( const char *name ) : MonitorModule(name) {
}

FooBar::FooBar( FooBar const & cpy ) : MonitorModule("FooBar") {
	(void)cpy;
}

FooBar::~FooBar( void ) {
}
	
void	FooBar::drawContent( int posX, int posY, int width, int height, Window const & win ) const {
	win.print(posX, posY, "42");
	(void)width;
	(void)height;
	(void)posY;
	(void)posX;
}
