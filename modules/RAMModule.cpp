#include "RAMModule.hpp"

RAMModule::RAMModule( void )
{

}

RAMModule::RAMModule( RAMModule const& rhs )
{
	*this = rhs;
}

RAMModule::~RAMModule( void ) {}

RAMModule &	RAMModule::operator=( RAMModule const& )
{
	return (*this);
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

	int length;
	int mib[2];
	int64_t physical_memory;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	length = sizeof(int64_t);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);

	// while (y < _height) {
	// 	x = 0;
	// 	while (x < width) {
	// 		win.print(posX + x, posY + y, "m");
	// 		++x;
	// 	}
	// 	++y;
	// }


}