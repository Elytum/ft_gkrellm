#include "includes/MonitorModule.hpp"
#include "includes/Window.hpp"
#include "includes/FooBar.hpp"
#include "includes/OSinfo.class.hpp"
#include "includes/RAMModule.hpp"
#include "includes/TimeModule.hpp"
#include "includes/NameModule.hpp"
#include "includes/CPUmod.class.hpp"
#include "includes/PonyModule.hpp"
#include "includes/NetworkModule.hpp"
#include "includes/NyanCatModule.hpp"
#include "includes/Tools.class.hpp"


#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>

void	parseConfig( Window & win ) {
	std::ifstream file(".config");
    std::string str; 
    std::string delimiter = " ";

	while (std::getline(file, str)) {
		size_t pos = 0;
		std::string token;
		std::vector<std::string>	array;

		while ((pos = str.find(delimiter)) != std::string::npos) {
			token = str.substr(0, pos);
			array.push_back(token);
			str.erase(0, pos + delimiter.length());
		}
		array.push_back(str);
		if (array[0] == "add" && array.size() >= 4) {
			int pos;
			if (array.size() == 3)
				pos = 0;
			else
				pos = atoi(array[3].c_str());
			if (array[1] == "module") {
				if (array[2] == "Name")
					win.addModule(new NameModule(), pos);
				else if (array[2] == "Time")
					win.addModule(new TimeModule(), pos);
				else if (array[2] == "Tools")
					win.addModule(new Tools(), pos);
				else if (array[2] == "NyanCat")
					win.addModule(new NyanCatModule(), pos);
				else if (array[2] == "PonyModule")
					win.addModule(new PonyModule(), pos);
				else if (array[2] == "OS")
					win.addModule(new OSinfo(), pos);
				else if (array[2] == "RAM")
					win.addModule(new RAMModule(), pos);
				else if (array[2] == "CPU")
					win.addModule(new CPUmod(), pos);
			}
		}
	}
}

int		main( void )
{

	Window				win;
	win.open();
	//parseConfig(win);
	win.addModule(new OSinfo(), 1);
	win.addModule(new RAMModule(), 1);
	win.addModule(new TimeModule(), 1);
	win.addModule(new NameModule(), 1);
	win.addModule(new CPUmod(), 1);
	win.addModule(new PonyModule(), 1);
	win.addModule(new NetworkModule(), 1);
	win.addModule(new NyanCatModule(), 1);
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
