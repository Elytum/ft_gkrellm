#define WIDTH 27
#define HEIGHT 10

#define FRAME1 \
"BBBBBBBBBBBWWBWWBBBBBBBBBBBB" \
"BBBBBBBBBBBBBWBBBBBBBBBBBBBB" \
"BBBBBBB             BBBBB  B" \
"RRRBBB WWWWWWWWWWW   MMMW  B" \
"YYYRRR WMMRMMMRMMMM        B" \
"GGGYYY WMMMMMRMMMMM  W  W  B" \
"CCCGGG WMMMMMMMMMMMMM    M B" \
"BBBCCC WWWWWWWWWWWWWWWWWW BB" \
"BBBBBB  BB BBBBBBB  BB  BBBB"

#include <math.h>

#include <NyanCatModule.hpp>

NyanCatModule::NyanCatModule( void ) : MonitorModule(WIDTH + 2, HEIGHT + 2, "NyanCatModule") {
}

NyanCatModule::NyanCatModule( std::string name ) : MonitorModule(WIDTH + 2, HEIGHT + 2, name) {
}

NyanCatModule::NyanCatModule( NyanCatModule const & cpy ) : MonitorModule(WIDTH + 2, HEIGHT + 2, "NyanCatModule") {
	(void)cpy;
}

NyanCatModule::~NyanCatModule( void ) {
}
	
void	NyanCatModule::drawContent( int posX, int posY, int width, int height, Window const & win ) {
	int pos = 0;
	int i = 0;

	for (int y = 0; (y < height && y <= HEIGHT); ++y) {
		i = pos;
		for (int x = 0; (x < width && x <= WIDTH); ++x) {
			win.print(posX + x, posY + y, FRAME1[i], FRAME1[i]);
			++i;
		}
		pos += width;
	}
}
