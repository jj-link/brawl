#include <types.h>
#pragma force_active on

extern u32 SOHtoNl(u32);
extern u16 SOHtoNs(u16);
extern u16 SONtoHs(u16);
extern char *SOInetNtoA(u32 *);
extern u32 fn_8035D728(void);
extern void *memcpy(void *, const void *, unsigned long);
extern int sendto(int, const void *, int, int, const void *, int);
extern char lbl_8059FB68[8];

void fn_80386ED4(u8 *self, u8 *packet, u8 *addr) {
    u8 pkt1[0x4c], pkt2[0x4c], pkt3[0x4c];
    u8 addr1[8], addr2[8], addr3[8];
    u32 inet4, inet1, inet2, inet3;
    int ip, sock;
    u16 port;

    if (*(int *)(self + 0x10) >= 2) {
        inet4 = *(u32 *)(addr + 4);
        SOInetNtoA(&inet4);
        SONtoHs(*(u16 *)(addr + 2));
        *(u32 *)(self + 0x30) = *(u32 *)(addr + 4);
        *(u16 *)(self + 0x34) = SONtoHs(*(u16 *)(addr + 2));
        self[0x36] = 1;

        if (packet[0x12] == 0) {
            memcpy(pkt1, lbl_8059FB68, 6);
            pkt1[6] = 3;
            pkt1[7] = 7;
            *(u32 *)(pkt1 + 8) = SOHtoNl(*(u32 *)(self + 8));
            *(u32 *)(pkt1 + 0xc) = *(u32 *)(self + 0x30);
            *(u16 *)(pkt1 + 0x10) = SOHtoNs(*(u16 *)(self + 0x34));
            pkt1[0x12] = self[0x36];
            pkt1[0x13] = *(int *)(self + 0x10) != 2;
            inet1 = *(u32 *)(self + 0x30);
            SOInetNtoA(&inet1);
            sock = *(int *)(self + 4);
            port = *(u16 *)(self + 0x34);
            ip = *(int *)(self + 0x30);
            sock = sock != -1 ? sock : *(int *)self;
            addr1[1] = 2;
            *(u16 *)(addr1 + 2) = SOHtoNs(port);
            *(int *)(addr1 + 4) = ip;
            sendto(sock, pkt1, 0x14, 0, addr1, 8);
            *(u32 *)(self + 0x2c) = fn_8035D728() + 0x2bc;
            *(int *)(self + 0x28) = 7;
            if (self[0x36] != 0) {
                self[0x37] = 1;
            }
        } else if (*(int *)(self + 0x10) == 2) {
            if (self[0x37] == 0) {
                memcpy(pkt2, lbl_8059FB68, 6);
                pkt2[6] = 3;
                pkt2[7] = 7;
                *(u32 *)(pkt2 + 8) = SOHtoNl(*(u32 *)(self + 8));
                *(u32 *)(pkt2 + 0xc) = *(u32 *)(self + 0x30);
                *(u16 *)(pkt2 + 0x10) = SOHtoNs(*(u16 *)(self + 0x34));
                pkt2[0x12] = self[0x36];
                pkt2[0x13] = *(int *)(self + 0x10) != 2;
                inet2 = *(u32 *)(self + 0x30);
                SOInetNtoA(&inet2);
                {
                int ip2, sock2;
                ip2 = *(int *)(self + 4);
                port = *(u16 *)(self + 0x34);
                sock2 = *(int *)(self + 0x30);
                ip2 = ip2 != -1 ? ip2 : *(int *)self;
                addr2[1] = 2;
                *(u16 *)(addr2 + 2) = SOHtoNs(port);
                *(int *)(addr2 + 4) = sock2;
                sendto(ip2, pkt2, 0x14, 0, addr2, 8);
                }
                *(u32 *)(self + 0x2c) = fn_8035D728() + 0x2bc;
                *(int *)(self + 0x28) = 7;
                if (self[0x36] != 0) {
                    self[0x37] = 1;
                }
            }
            *(int *)(self + 0x10) = 3;
            *(u32 *)(self + 0x2c) = fn_8035D728() + 0x1388;
        } else if (packet[0x13] == 0) {
            memcpy(pkt3, lbl_8059FB68, 6);
            pkt3[6] = 3;
            pkt3[7] = 7;
            *(u32 *)(pkt3 + 8) = SOHtoNl(*(u32 *)(self + 8));
            *(u32 *)(pkt3 + 0xc) = *(u32 *)(self + 0x30);
            *(u16 *)(pkt3 + 0x10) = SOHtoNs(*(u16 *)(self + 0x34));
            pkt3[0x12] = self[0x36];
            pkt3[0x13] = *(int *)(self + 0x10) != 2;
            inet3 = *(u32 *)(self + 0x30);
            SOInetNtoA(&inet3);
            {
            int ip3;
            ip3 = *(int *)(self + 4);
            port = *(u16 *)(self + 0x34);
            sock = *(int *)(self + 0x30);
            ip3 = ip3 != -1 ? ip3 : *(int *)self;
            addr3[1] = 2;
            *(u16 *)(addr3 + 2) = SOHtoNs(port);
            *(int *)(addr3 + 4) = sock;
            sendto(ip3, pkt3, 0x14, 0, addr3, 8);
            }
            *(u32 *)(self + 0x2c) = fn_8035D728() + 0x2bc;
            *(int *)(self + 0x28) = 7;
            if (self[0x36] != 0) {
                self[0x37] = 1;
            }
        }
    }
}
