/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmod.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:20:35 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 14:39:11 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUmod.class.hpp"
#include <string>

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

CPUmod::CPUmod( void ) : MonitorModule(45, 9, "CPU informations")
{
	int a = GetCPULoad() * 100;
	this->_info.cpuLoad = a;
	this->_info.cpuFree = 100 - a;
	this->_info.byteOrder = this->ft_sysctl_int(CTL_HW, HW_BYTEORDER);
	this->_info.coreNB = this->ft_sysctl_int(CTL_HW ,HW_NCPU);
	ft_sysctl_clock(CTL_KERN, KERN_CLOCKRATE);
}

void	CPUmod::printInfo( void ) const
{
}

float	CPUmod::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
	float ret = 1.0f-((totalTicksSinceLastTime > 0) ? (static_cast<float>(idleTicksSinceLastTime))/totalTicksSinceLastTime : 0);
	_previousTotalTicks = totalTicks;
	_previousIdleTicks  = idleTicks;
	return ret;
}


float CPUmod::GetCPULoad( )
{
	float sysLoadPercentage;
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
		sysLoadPercentage = CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else
		return -1.0f;
	return sysLoadPercentage;
}

long    CPUmod::ft_sysctl_int(int un, int deux)
{
	int64_t res = {0};
	int mib[2];
	mib[0] = un;
	mib[1] = deux;
	size_t size = sizeof(int64_t);
	sysctl(mib, 2, &res, &size, NULL, 0);
	return (res);
}
void    CPUmod::ft_sysctl_clock(int sys, int flag)
{
	struct clockinfo res;
	res.hz = 0;
	res.tick = 0;
	res.tickadj = 0;
	res.stathz = 0;
	res.profhz = 0;
	int mib[2];
	mib[0] = sys;
	mib[1] = flag;
	size_t size = sizeof(struct clockinfo);
	sysctl(mib, 2, &res, &size, NULL, 0);
	this->_info.clockinfo = res;
}

void 	CPUmod::updateInfo( void )
{
	int a = GetCPULoad() * 100;
	this->_info.cpuLoad = a;
	this->_info.cpuFree = 100 - a;
	this->_info.byteOrder = this->ft_sysctl_int(CTL_HW, HW_BYTEORDER);
	this->_info.coreNB = this->ft_sysctl_int(CTL_HW ,HW_NCPU);
	ft_sysctl_clock(CTL_KERN, KERN_CLOCKRATE);

	size_t	brand = sizeof(_info.brand);

	sysctlbyname("machdep.cpu.brand_string", &_info.brand, &brand, NULL, 0);
}

	template< typename T >
void	printType( int posX, int posY, int width, int height, Window const &win, char const *s, T index)
{
	win.print(posX + 1, posY, s);
	win.print(posX + 1 + strlen(s), posY, index);
	width = height = 0;
}

void	CPUmod::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	updateInfo();

	(void)win;
	printType(posX, posY, width, height, win, "", _info.brand);
	posY++;
	printType(posX, posY, width, height, win, "core: ", std::to_string(_info.coreNB).c_str());
	posY++;
	printType(posX, posY, width, height, win, "clock freq: ", std::to_string(_info.clockinfo.hz).c_str());
	posY++;
	printType(posX, posY, width, height, win, "ms per hz tick: ", std::to_string(_info.clockinfo.tick).c_str());
	posY++;
	printType(posX, posY, width, height, win, "cpuLoad: ", std::to_string(_info.cpuLoad).c_str());
	posY++;
	printType(posX, posY, width, height, win, "cpuFree: ", std::to_string(_info.cpuFree).c_str());
}

CPUmod::~CPUmod( void )
{
}
