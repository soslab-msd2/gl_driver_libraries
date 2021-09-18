
#ifndef GLDRIVER_H
#define GLDRIVER_H

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <mutex>

#include "serial/serial.h"
#include "udp/udp.h"


class GL
{
public:
	struct framedata_t
	{
		std::vector<double> angle;
		std::vector<double> distance;
		std::vector<double> pulse_width;
	};

public:
	GL(std::string& gl_udp_ip, int gl_udp_port, int pc_udp_port);
	GL(std::string& gl_serial_name, uint32_t gl_serial_baudrate);
	~GL();

	std::string GetSerialNum(void);
	void ReadFrameData(GL::framedata_t& frame_data, bool filter_on=true);
	void SetFrameDataEnable(bool framedata_enable);

private:
	void ThreadCallBack(void);
	bool thread_running = true;
	std::thread th;
};

#endif