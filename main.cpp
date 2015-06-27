#include "graphic/MonitorModule.hpp"
#include "graphic/Window.hpp"
#include "modules/RAMModule.hpp"

int		main( void )
{
	Window			win;
	MonitorModule	mod;
	RAMModule		test;

	MonitorModule	tooBig("tooBiggggggg");
	MonitorModule	tooSmall("a");

	win.open();
	win.addModule(tooBig, 0);
	win.addModule(mod, 0);
	win.addModule(test, 1);
	win.addModule(mod, 1);
	win.addModule(mod, 1);
	win.addModule(tooBig, 3);
	win.addModule(tooSmall, 6);
	while (42) {
		win.refresh();
		win.flush();
		if (wgetch(win.getWindow()) == 'a')
			break;
	}
	win.close();
	return (0);
	(void)win;
}


/*
Monitor module: Pointeur sur fonction qui prend un x, y, width, height et window
et qui affiche en fonction.

Exemple: cpuInfo

*/