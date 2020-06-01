#ifndef NET_ICMP_H
#define NET_ICMP_H

#include <stdint.h>

#define ICMP_ECHO 0
#define ICMP_REPLY 0
#define ICMP_REQUEST 8

struct sk_buff;

struct __attribute__((packed)) icmp_packet
{
  uint8_t type;
  uint8_t code;
  uint16_t checksum;
  uint32_t rest_of_header;
  uint8_t payload[];
};

struct icmp_packet *icmp_create_packet(uint8_t type, uint32_t rest_of_header);
void icmp_reply(uint32_t dest_ip, uint32_t rest_of_header);
int32_t icmp_rcv(struct sk_buff *skb);

#endif