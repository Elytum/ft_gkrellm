#include <MonitorModule.hpp>
#include <Window.hpp>

int		main( void )
{
	Window			win;
	MonitorModule	mod;

	win.open();
	win.addModule(mod, 0);
	win.addModule(mod, 0);
	win.addModule(mod, 1);
	win.addModule(mod, 1);
	win.addModule(mod, 1);
	win.addModule(mod, 1);
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