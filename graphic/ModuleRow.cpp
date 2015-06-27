#include <ModuleRow.hpp>

ModuleRow::ModuleRow( void ) : width(DEFAULT_WIDTH) {
}

ModuleRow::~ModuleRow( void ) {
}

void								ModuleRow::addModule( MonitorModule & mod ) {
	modules.push_back(mod);
}

const std::vector<MonitorModule>	ModuleRow::getModules( void ) const {
	return modules;
}

int									ModuleRow::getWidth( void ) const {
	return width;
}

MonitorModule&						ModuleRow::operator[](int pos)	{
	if (pos < 0)
		throw std::exception();
	else if (pos >= static_cast<int>(modules.size()))
		modules.resize(pos + 1);
	return modules[pos];
};

void								ModuleRow::draw( int x, int y, Window const & win ) const {
	int s = modules.size();
	int i = 0;

	while (i < s) {
		modules[i].draw(x, y, width, win);
		y += modules[i].getHeight();
		++i;
	}
}