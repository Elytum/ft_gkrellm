#include <MonitorModule.hpp>
#include <Window.hpp>
#include <FooBar.hpp>
#include <RAMModule.hpp>

int		main( void )
{
	Window			win;
	RAMModule*			tooSmall = new RAMModule;

	win.open();
	win.addModule(tooSmall, 6);
	while (42) {
		win.refresh();
		win.flush();
		if (wgetch(win.getWindow()) == 'q')
			break;
	}
	win.close();
	return (0);
	(void)win;
}
