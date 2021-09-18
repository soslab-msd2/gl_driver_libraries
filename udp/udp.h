
#ifndef UDP_H
#define UDP_H

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <mutex>


#ifdef _WIN32

#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

#else

#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#endif


class UDP
{
public:
	UDP(std::string& target_udp_ip, int target_udp_port, int pc_udp_port);
	~UDP();

    bool isOpen(void);
    void SendPacket(std::vector<uint8_t> send_packet);
    int RecvPacket(std::vector<uint8_t>& send_packet);

private:
    int sockfd;
    struct sockaddr_in target_addr, pc_addr;
    bool is_open = false;
};

#endif