#include <MonitorModule.hpp>
#include <Window.hpp>

int		main( void )
{
	Window			win;
	MonitorModule	mod;

	win.open();
	win.addModule(mod);
	win.drawModule(mod);
	// win.print(0, 0, "Lol");
	win.flush();
	while (42);
	win.close();
	return (0);
	(void)win;
}