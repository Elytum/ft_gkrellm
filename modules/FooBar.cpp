#include <math.h>

#include <FooBar.hpp>

FooBar::FooBar( void ) : MonitorModule(15, "FooBar") {
}

FooBar::FooBar( const char *name ) : MonitorModule(15, name) {
}

FooBar::FooBar( FooBar const & cpy ) : MonitorModule(15, "FooBar") {
	(void)cpy;
}

FooBar::~FooBar( void ) {
}
	
void	FooBar::drawContent( int posX, int posY, int width, int height, Window const & win ) const {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			win.print(posX + x, posY + y, (std::to_string(rand() % 2)).c_str());
		}
	}
}
