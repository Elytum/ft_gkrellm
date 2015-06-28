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
	char				c;
	Window				win;
	RAMModule*			infoRAM = new RAMModule();
	NameModule*			infoName = new NameModule();
	OSinfo*				infoOS = new OSinfo();
	TimeModule*			infoTime = new TimeModule();
	CPUmod*				infoCPU = new CPUmod();
	PonyModule*			infoPony = new PonyModule();
	NyanCatModule*		infoNyanCat = new NyanCatModule();
	Tools*				infoTools = new Tools();

	win.open();
	win.color_tab = 0;
	
	win.addModule(infoTime, 1);
	win.addModule(infoTools, 1);
	win.addModule(infoNyanCat, 4);
	win.addModule(infoPony, 1);
	win.addModule(infoOS, 2);
	win.addModule(infoRAM, 3);
	win.addModule(infoCPU, 3);

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
