#include "udp.h"



UDP::UDP(std::string& target_udp_ip, int target_udp_port, int pc_udp_port)
{
    if ( (sockfd=socket(AF_INET, SOCK_DGRAM, 0)) == -1 ) 
    { 
		std::cout << "[ERROR] Socket creation failed" << std::endl; 
        return;
	} 

	memset(&target_addr, 0, sizeof(target_addr)); 
	target_addr.sin_family = AF_INET; 
	target_addr.sin_port = htons(target_udp_port); 
    const char * c = target_udp_ip.c_str();
	target_addr.sin_addr.s_addr = inet_addr(c);

    memset(&pc_addr, 0, sizeof(pc_addr)); 
	pc_addr.sin_family = AF_INET; 
	pc_addr.sin_port = htons(pc_udp_port); 
    pc_addr.sin_addr.s_addr = htonl( INADDR_ANY );

    if ( bind(sockfd,(struct sockaddr *)&pc_addr,sizeof(pc_addr)) == -1 ) 
    { 
		std::cout << "[ERROR] Bind failed" << std::endl; 
		return;
	} 
    
    std::cout << "Socket START [" << sockfd << "]" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    is_open = true;
}

UDP::~UDP()
{
    close(sockfd);
    std::cout << "Socket END" << std::endl;
}

bool UDP::isOpen(void)
{
    return is_open;
}

void UDP::SendPacket(std::vector<uint8_t> send_packet)
{
    sendto(sockfd, (char*)&send_packet[0], send_packet.size(), 0, (const struct sockaddr *) &target_addr, sizeof(target_addr));
}

int UDP::RecvPacket(std::vector<uint8_t>& recv_packet)
{
    int recv_len = recv(sockfd, (char*)&recv_packet[0], recv_packet.size(), 0);

    return recv_len;
}