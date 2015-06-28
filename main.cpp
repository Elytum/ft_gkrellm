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

//TODO
//remove all c++11 functiosn (to_string)
//add all monitormodule function to IMonitorModule (sujet)
// si possible, laisser addmodule utiliser Imonitormodule
//add un IMonitorDisplay qui contient tout les print, printbox, et printline
int		main( void )
{
	Window			win;
	NameModule*		infoName = new NameModule();
	RAMModule*		tooSmall = new RAMModule();
	OSinfo*			infoOS = new OSinfo();
	TimeModule*		infoTime = new TimeModule();
	CPUmod*			infoCPU = new CPUmod();
	PonyModule*		infoPony = new PonyModule();
	NetworkModule*	infoNetwork = new NetworkModule();

	win.open();
	win.addModule(tooSmall, 1);
	win.addModule(infoOS, 2);
	win.addModule(infoTime, 1);
	win.addModule(infoName, 1);
	win.addModule(infoCPU, 2);
	win.addModule(infoPony, 2);
	win.addModule(infoNetwork, 3);
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
