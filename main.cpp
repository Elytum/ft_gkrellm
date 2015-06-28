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
	win.open();
	int					color_tab;

	win.setColorTab(0);

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
		c = wgetch(win.getWindow());
		if (c == 'q')
			break;
		if (c == '+')
		{
			color_tab = win.getColorTab();
			if (color_tab >= 3)
			{
				win.setColorTab(1);
			}
			else
			{
				win.setColorTab(color_tab + 1);
			}
			c = 'Y';
		}
		if (c == '-')
		{
			color_tab = win.getColorTab();
			if (color_tab <= 0)
			{
				win.setColorTab(3);
			}
			else
			{
				win.setColorTab(color_tab - 1);
			}
			c = 'Y';
		}
	}
	win.close();
	return (0);
	(void)win;
}
