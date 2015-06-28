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
	char				c;
	Window				win;
	NameModule*			infoName = new NameModule();
	RAMModule*			tooSmall = new RAMModule();
	OSinfo*				infoOS = new OSinfo();
	TimeModule*			infoTime = new TimeModule();
	CPUmod*				infoCPU = new CPUmod();
	PonyModule*			infoPony = new PonyModule();
	NetworkModule*		infoNetwork = new NetworkModule();
	NyanCatModule*		infoNyanCat = new NyanCatModule();

	win.open();
	win.addModule(tooSmall, 1);
	win.addModule(infoOS, 2);
	win.addModule(infoTime, 1);
	win.addModule(infoName, 1);
	win.addModule(infoCPU, 2);
	win.addModule(infoPony, 2);
	win.addModule(infoNetwork, 3);
	win.addModule(infoNyanCat, 3);
	win.color_tab[0] = 0;
	win.color_tab[1] = 1;
	win.color_tab[2] = 2;
	win.color_tab[3] = 3;
	while (42) {
		win.refresh();
		win.flush();
		c = wgetch(win.getWindow();
		if (c == 'q')
			break;
		if (c == '+')
		{
			if (win.color_tab >= 3)
			{
				win.color_tab = 1;
			}
			else
			{
				win.color_tab = win.color_tab + 1;
			}
			c = 'Y';
		}
		if (c == '-')
		{
			if (win.color_tab <= 0)
			{
				win.color_tab = 3;
			}
			else
			{
				win.color_tab = win.color_tab - 1;
			}
			c = 'Y';
		}
	}
	win.close();
	return (0);
	(void)win;
}
