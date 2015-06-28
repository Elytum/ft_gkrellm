#include <MonitorModule.hpp>
#include <Window.hpp>
#include <FooBar.hpp>
#include "OSinfo.class.hpp"
#include "RAMModule.hpp"

int		main( void )
{
	Window			win;
	FooBar*			tooSmall = new FooBar("");
	OSinfo*			infoOS = new OSinfo();

	win.open();
	win.addModule(tooSmall, 42);
	win.addModule(infoOS, 42);
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
