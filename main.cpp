#include <MonitorModule.hpp>
#include <Window.hpp>
#include <sys/types.h>
#include <sys/sysctl.h>
#include "OSinfo.class.hpp"


int		main( void )
{
	OSinfo		instance;		
	return 0;
}

/*
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

*/
