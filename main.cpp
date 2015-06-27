#include <MonitorModule.hpp>
#include <Window.hpp>

int		main( void )
{
	Window			win;
	MonitorModule	mod;
	MonitorModule	test("Test");

	win.open();
	win.addModule(mod, 0);
	win.addModule(mod, 0);
	win.addModule(test, 1);
	win.addModule(mod, 1);
	win.addModule(test, 1);
	win.addModule(mod, 1);
	win.addModule(mod, 3);
	win.refresh();
	// win.drawModule(mod);
	
	// win.print(0, 0, "Lol");
	win.flush();
	char tmp[2];
	read(1, tmp, 1);
	win.close();
	return (0);
	(void)win;
}


/*
Monitor module: Pointeur sur fonction qui prend un x, y, width, height et window
et qui affiche en fonction.

Exemple: cpuInfo

*/