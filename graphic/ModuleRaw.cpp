#include <ModuleRaw.hpp>

ModuleRaw::ModuleRaw( void ) : width(DEFAULT_WIDTH) {
}

ModuleRaw::~ModuleRaw( void ) {
}

void								ModuleRaw::addModule( MonitorModule & mod ) {
	modules.push_back(mod);
}

const std::vector<MonitorModule>	ModuleRaw::getModules( void ) const {
	return modules;
}

int									ModuleRaw::getWidth( void ) const {
	return width;
}

MonitorModule&						ModuleRaw::operator[](int pos)	{
	if (pos < 0)
		throw std::exception();
	else if (pos >= static_cast<int>(modules.size()))
		modules.resize(pos + 1);
	return modules[pos];
};

void								ModuleRaw::draw( int x, int y, Window const & win ) const {
	int s = modules.size();
	int i = 0;

	while (i < s) {
		modules[i].draw(x, y, width, win);
		y += modules[i].getHeight();
		++i;
	}
}