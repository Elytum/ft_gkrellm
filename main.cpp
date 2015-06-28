#include <MonitorModule.hpp>
#include <Window.hpp>
#include <FooBar.hpp>
#include "OSinfo.class.hpp"
#include "RAMModule.hpp"
#include "TimeModule.hpp"
#include "NameModule.hpp"
#include "CPUmod.class.hpp"
#include "PonyModule.hpp"
#include "NetworkModule.hpp"
#include "NyanCatModule.hpp"
#include "Tools.class.hpp"

int		main( void )
{

	Window				win;
	win.open();
	win.addModule(new NameModule(), 1);
	win.addModule(new TimeModule(), 1);
	win.addModule(new Tools(), 1);
	win.addModule(new NyanCatModule(), 4);
	win.addModule(new PonyModule(), 1);
	win.addModule(new OSinfo(), 2);
	win.addModule(new RAMModule(), 3);
	win.addModule(new CPUmod(), 3);
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
