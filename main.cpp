#include <MonitorModule.hpp>
#include <Window.hpp>
#include <FooBar.hpp>
#include "OSinfo.class.hpp"
#include "RAMModule.hpp"
#include "TimeModule.hpp"
#include "NameModule.hpp"

int		main( void )
{
	Window			win;
	//FooBar*			tooSmall = new FooBar("");
	//OSinfo*			infoOS = new OSinfo();
	//TimeModule*		infoTime = new TimeModule();
	NameModule*		infoName = new NameModule();

	win.open();
	//win.addModule(tooSmall, 42);
	//win.addModule(infoOS, 42);
	//win.addModule(infoTime, 42);
	win.addModule(infoName, 42);
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
