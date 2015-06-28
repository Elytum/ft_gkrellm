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

//TODO
//remove all c++11 functiosn (to_string)
//add all monitormodule function to IMonitorModule (sujet)
// si possible, laisser addmodule utiliser Imonitormodule
//add un IMonitorDisplay qui contient tout les print, printbox, et printline
int		main( void )
{

	Window				win;
	
	win.open();
	win.addModule(new RAMModule(), 1);
	win.addModule(new OSinfo(), 2);
	win.addModule(new TimeModule(), 1);
	win.addModule(new NameModule(), 1);
	win.addModule(new CPUmod(), 2);
	win.addModule(new PonyModule(), 2);
	// win.addModule(new NetworkModule(), 3);
	win.addModule(new NyanCatModule(), 3);
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
