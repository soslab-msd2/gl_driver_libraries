
#ifndef UDP_H
#define UDP_H

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


class UDP
{
public:
	UDP(std::string& target_udp_ip, int target_udp_port, int pc_udp_port);
	~UDP();

    bool isOpen(void);
    void SendPacket(std::vector<uint8_t> send_packet);
    int RecvPacket(std::vector<uint8_t>& send_packet);
};

#endif