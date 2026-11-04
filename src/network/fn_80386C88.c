#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 SOHtoNl(u32);
extern u16 SOHtoNs(u16);
extern u16 SONtoHs(u16);
extern char *SOInetNtoA(u32 *);
extern u32 fn_8035D728(void);
extern void fn_80385D94(void *, int, int, int);
extern void *memcpy(void *, const void *, unsigned long);
extern int sendto(int, const void *, int, int, const void *, int);
extern char lbl_8059FB68[8];

void fn_80386C88(u8 *self, u8 *packet, u8 *addr) {
    u32 spC, sp8;
    u8 sp18[8], sp10[8];
    u8 sp20[0x9c];
#define sp6c (sp20 + 0x4c)
    u16 port;
    int sock, ip, result;

    spC = *(u32 *)(packet + 0xc);
    SOInetNtoA(&spC);
    SONtoHs(*(u16 *)(packet + 0x10));

    if (packet[0x13] == 0) {
        memcpy(sp6c, lbl_8059FB68, 6);
        sp6c[6] = 3;
        sp6c[7] = 6;
        *(u32 *)(sp6c + 8) = SOHtoNl(*(u32 *)(self + 8));
        sp6c[13] = *(int *)(self + 0xc);

        port = SONtoHs(*(u16 *)(addr + 2));
        ip = *(int *)(addr + 4);
        sock = *(int *)self;
        sp18[1] = 2;
        *(u16 *)(sp18 + 2) = SOHtoNs(port);
        *(int *)(sp18 + 4) = ip;
        sendto(sock, sp6c, 0x15, 0, sp18, 8);
    }

    if (*(int *)(self + 0x10) < 2) {
        if (packet[0x13] != 0) {
            result = 4;
            if (packet[0x13] == 1) {
                result = 1;
            } else if (packet[0x13] == 2) {
                result = 2;
            }
            fn_80385D94(self, result, -1, 0);
            return;
        }

        *(u32 *)(self + 0x30) = *(u32 *)(packet + 0xc);
        *(u16 *)(self + 0x34) = SONtoHs(*(u16 *)(packet + 0x10));
        *(int *)(self + 0x24) = 0;
        *(int *)(self + 0x10) = 2;
        ((void (*)(int, int))*(u32 *)(self + 0x38))(
            2, *(int *)(self + 0x40));

        memcpy(sp20, lbl_8059FB68, 6);
        sp20[6] = 3;
        sp20[7] = 7;
        *(u32 *)(sp20 + 8) = SOHtoNl(*(u32 *)(self + 8));
        *(u32 *)(sp20 + 12) = *(u32 *)(self + 0x30);
        *(u16 *)(sp20 + 16) = SOHtoNs(*(u16 *)(self + 0x34));
        sp20[18] = self[0x36];
        sp20[19] = *(int *)(self + 0x10) != 2;

        sp8 = *(u32 *)(self + 0x30);
        SOInetNtoA(&sp8);
        ip = *(int *)(self + 4);
        port = *(u16 *)(self + 0x34);
        sock = *(int *)(self + 0x30);
        ip = ip != -1 ? ip : *(int *)self;
        sp10[1] = 2;
        *(u16 *)(sp10 + 2) = SOHtoNs(port);
        *(int *)(sp10 + 4) = sock;
        sendto(ip, sp20, 0x14, 0, sp10, 8);

        *(u32 *)(self + 0x2c) = fn_8035D728() + 700;
        *(int *)(self + 0x28) = 7;
        if (self[0x36] != 0) {
            self[0x37] = 1;
        }
    }
#undef sp6c
}
