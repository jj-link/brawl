#include <types.h>
#pragma force_active on

typedef struct NetObj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
} NetObj;

extern int SOHtoNl(int);
extern short SOHtoNs(int);
extern char *SOInetNtoA(int *);
extern unsigned short SONtoHs(unsigned short);
extern int fn_80385CF8(void);
extern int fn_803A7AF4(void);
extern int fn_8035D728(void);
extern int getsockname(int, void *, int *);
extern int sendto(int, void *, int, int, void *, int);
extern void *memcpy(void *, const void *, unsigned int);
extern char *strcpy(char *, const char *);
extern unsigned int strlen(const char *);
extern char lbl_80534808[];
extern char lbl_8059FB68[8];
extern int lbl_805A10F4, lbl_805A10F8, lbl_805A10FC;

void fn_80385F88(NetObj *arg0) {
    unsigned char buf[0x60];
    char sa40[8];
    char sa38[8];
    char sa30[8];
    char sa28[8];
    char sa20[8];
    int in18;
    int in14;
    int in10;
    int inC;
    int namelen;
    unsigned char *p;
    int len;
    int sock;
    unsigned int temp;
    unsigned int idret;
    unsigned int port;

    p = buf;
    memcpy(p, lbl_8059FB68, 6);
    p[6] = 3;
    p[7] = 0;
    *(int *)(p + 8) = SOHtoNl(arg0->unk8);
    p[0xD] = (unsigned char)arg0->unkC;
    temp = arg0->unk4;
    p[0xE] = (unsigned char)(((unsigned int)(-1 - (int)temp) | (temp + 1)) >> 31);
    fn_80385CF8();
    idret = fn_803A7AF4();
    p[0xF] = (unsigned char)(idret >> 24);
    p[0x10] = (unsigned char)(idret >> 16);
    p[0x11] = (unsigned char)(idret >> 8);
    p[0x12] = (unsigned char)idret;
    p[0x13] = 0;
    p[0x14] = 0;
    strcpy((char *)p + 0x15, lbl_80534808);
    len = strlen(lbl_80534808) + 0x16;

    if (p[0xE] != 0 && arg0->unk14 == 0) {
        int ip;
        p[0xC] = 0;
        in18 = lbl_805A10F4;
        SOInetNtoA(&in18);
        sock = arg0->unk4;
        ip = lbl_805A10F4;
        sa40[1] = 2;
        *(short *)(sa40 + 2) = SOHtoNs(0x6cfd);
        *(int *)(sa40 + 4) = ip;
        sendto(sock, p, len, 0, sa40, 8);
    }
    if (arg0->unk18 == 0) {
        int ip;
        p[0xC] = 1;
        in14 = lbl_805A10F4;
        SOInetNtoA(&in14);
        sock = arg0->unk0;
        ip = lbl_805A10F4;
        sa38[1] = 2;
        *(short *)(sa38 + 2) = SOHtoNs(0x6cfd);
        *(int *)(sa38 + 4) = ip;
        sendto(sock, p, len, 0, sa38, 8);
    }
    sock = (p[0xE] != 0) ? arg0->unk4 : arg0->unk0;
    namelen = 8;
    if (getsockname(sock, sa30, &namelen) == -1) {
        port = 0;
    } else {
        port = *(unsigned short *)(sa30 + 2);
    }
    port = SONtoHs(port);
    p[0x14] = (unsigned char)port;
    p[0x13] = (unsigned char)(port >> 8);

    if (arg0->unk1C == 0) {
        int ip;
        p[0xC] = 2;
        in10 = lbl_805A10F8;
        SOInetNtoA(&in10);
        sock = arg0->unk0;
        ip = lbl_805A10F8;
        sa28[1] = 2;
        *(short *)(sa28 + 2) = SOHtoNs(0x6cfd);
        *(int *)(sa28 + 4) = ip;
        sendto(sock, p, len, 0, sa28, 8);
    }
    if (arg0->unk20 == 0) {
        int s4;
        int ip;
        p[0xC] = 3;
        inC = lbl_805A10FC;
        SOInetNtoA(&inC);
        s4 = arg0->unk0;
        ip = lbl_805A10FC;
        sa20[1] = 2;
        *(short *)(sa20 + 2) = SOHtoNs(0x6cfd);
        *(int *)(sa20 + 4) = ip;
        sendto(s4, p, len, 0, sa20, 8);
    }
    arg0->unk2C = fn_8035D728() + 0x1F4;
    arg0->unk28 = 0xA;
}
