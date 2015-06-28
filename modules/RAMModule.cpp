#include "RAMModule.hpp"

RAMModule::RAMModule( void ):MonitorModule()
{

}

RAMModule::RAMModule( RAMModule const& rhs )
{
	*this = rhs;
}

RAMModule::~RAMModule( void ) {}

RAMModule &	RAMModule::operator=( RAMModule const& )
{
	return (*this);
}

#define BSIZE (1024 * 1024)
#define	BNAME ("M")

	
void	RAMModule::drawContent( int posX, int posY, int width, int height, Window const & win ) const{

	(void)width;
	(void)height;

	int64_t physical_memory;
	size_t length = sizeof(int64_t);
	sysctlbyname("hw.memsize", &physical_memory, &length, NULL, 0);
	string display = std::to_string(physical_memory / BSIZE) + BNAME;



	sysctlbyname("vm.swapusage", &physical_memory, &length, NULL, 0);
	display += "/" + std::to_string(physical_memory / BSIZE) + BNAME;



	win.print(posX + 1, posY + 1, display.c_str());
	
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
										(host_info64_t)&vm_stats, &count))
	{
		long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

		long long used_memory = ((int64_t)vm_stats.active_count +
								 (int64_t)vm_stats.inactive_count +
								 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;	
		display = std::to_string(free_memory / BSIZE) + BNAME + "+" + std::to_string(used_memory / BSIZE) + BNAME;
		win.print(posX + 1, posY + 2, display.c_str());
	}
}