#include <MonitorModule.hpp>
#include <Window.hpp>
#include <FooBar.hpp>
#include "OSinfo.class.hpp"
#include "RAMModule.hpp"
#include "TimeModule.hpp"
#include "NameModule.hpp"
#include "CPUmod.class.hpp"
#include "PonyModule.hpp"
#include "NyanCatModule.hpp"

int		main( void )
{
	Window				win;
	RAMModule*			infoRAM = new RAMModule();
	NameModule*			infoName = new NameModule();
	OSinfo*				infoOS = new OSinfo();
	TimeModule*			infoTime = new TimeModule();
	CPUmod*				infoCPU = new CPUmod();
	PonyModule*			infoPony = new PonyModule();
	NyanCatModule*		infoNyanCat = new NyanCatModule();

	win.open();
	win.addModule(infoName, 1);
	win.addModule(infoTime, 1);
	win.addModule(infoNyanCat, 4);
	win.addModule(infoPony, 5);
	win.addModule(infoOS, 2);
	win.addModule(infoRAM, 3);
	win.addModule(infoCPU, 3);
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
