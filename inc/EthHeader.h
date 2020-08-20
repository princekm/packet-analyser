#ifndef ETHHEADER_H
#define ETHHEADER_H


#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#ifndef _WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

/* default snap length (maximum bytes per packet to capture) */
#define SNAP_LEN 1518

/* ethernet headers are always exactly 14 bytes [1] */
#define SIZE_ETHERNET 14

/* Ethernet addresses are 6 bytes */
#define ETHER_ADDR_LEN	6

/* Ethernet header */
struct sniff_ethernet {
        qint8  ether_dhost[ETHER_ADDR_LEN];    /* destination host address */
        qint8  ether_shost[ETHER_ADDR_LEN];    /* source host address */
        qint16 ether_type;                     /* IP? ARP? RARP? etc */
};

/* IP header */
struct sniff_ip {
        qint8  ip_vhl;                 /* version << 4 | header length >> 2 */
        qint8  ip_tos;                 /* type of service */
        qint16 ip_len;                 /* total length */
        qint16 ip_id;                  /* identification */
        qint16 ip_off;                 /* fragment offset field */
        #define IP_RF 0x8000            /* reserved fragment flag */
        #define IP_DF 0x4000            /* dont fragment flag */
        #define IP_MF 0x2000            /* more fragments flag */
        #define IP_OFFMASK 0x1fff       /* mask for fragmenting bits */
        qint8  ip_ttl;                 /* time to live */
        qint8  ip_p;                   /* protocol */
        qint16 ip_sum;                 /* checksum */
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
};
#define IP_HL(ip)               (((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)                (((ip)->ip_vhl) >> 4)

/* TCP header */
typedef u_int tcp_seq;

struct sniff_udp{
    qint16 th_sport;               /* source port */
    qint16 th_dport;               /* destination port */
    qint16 th_len;                 /* length  */
    qint16 th_chsum;                 /* checksum  */

};

struct sniff_tcp {
        qint16 th_sport;               /* source port */
        qint16 th_dport;               /* destination port */
        tcp_seq th_seq;                 /* sequence number */
        tcp_seq th_ack;                 /* acknowledgement number */
        qint8  th_offx2;               /* data offset, rsvd */
#define TH_OFF(th)      (((th)->th_offx2 & 0xf0) >> 4)
        qint8  th_flags;
        #define TH_FIN  0x01
        #define TH_SYN  0x02
        #define TH_RST  0x04
        #define TH_PUSH 0x08
        #define TH_ACK  0x10
        #define TH_URG  0x20
        #define TH_ECE  0x40
        #define TH_CWR  0x80
        #define TH_FLAGS        (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
        qint16 th_win;                 /* window */
        qint16 th_sum;                 /* checksum */
        qint16 th_urp;                 /* urgent pointer */
};


#endif
