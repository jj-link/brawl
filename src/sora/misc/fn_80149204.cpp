#include <types.h>
#include <nt/nt_offline.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {
int fn_8033CAC0(int, int);
void fn_8033CAE0(int*, int*);
int fn_80339F84(unsigned char, void*, void*, int, int, int, void*, int, int, int, int);
int fn_8033A0C8(unsigned char, void*, int, void*, int, int, int, int);
int fn_8033A200(int, void*, int, void*, int, int, void*, int);
unsigned char fn_8033C180(int, void*, int*);
unsigned char fn_8033C5D8(int, void*, char*);
int snprintf(char*, unsigned long, const char*, ...);
char* strcpy(char*, const char*);
extern char lbl_8045F7A8[];
extern char lbl_8059E770[4];
extern char lbl_8059E794[6];
extern char lbl_8059E7A0[8];
extern char lbl_8059E7A8[5];
extern char lbl_8059E7B0[5];
extern int lbl_805A03FC;
extern int lbl_805A0400;
extern int lbl_805A0404;
extern char* lbl_805A0434;
extern float lbl_805A2B68;
void fn_80148A74(void);
void fn_80148A94(void);
void fn_8014B874(void);
}

extern "C" int fn_80149204(void) {
    int r;
    char* base = lbl_8045F7A8;
    char buf[0x80];
    int a2c, a28, a24, a20, a1c, a18;

    lbl_805A0434[0x3413] = 0;
    switch (lbl_805A03FC) {
    case 1:
        netReport(base + 0x868);
        {
            int x = *(int*)(lbl_805A0434 + 0x3494);
            if (x < 0) {
                x = 0x5265C00;
            }
            if (fn_8033CAC0(x, x) == 1) {
                fn_8033CAE0(&a28, &a2c);
                netReport(base + 0x7e0, a2c);
            } else {
                netReport(base + 0x7f0);
            }
        }
        strcpy(lbl_805A0434 + 0x344c, lbl_805A0434 + 0x33cf);
        {
            char** nameTable = (char**)(base + 0x848);
            char* serverName = (*(char***)&nameTable)[((int*)g_muWifiInterfaceTask)[0x1b]];
            snprintf(lbl_805A0434 + 0x344c, 0x3f, lbl_8059E794,
                     lbl_805A0434 + 0x33cf, serverName);
        }
        {
            int c = fn_8033C5D8(0x64, lbl_8059E7A0, lbl_805A0434 + 0x344c);
            netReport(base + 0x888, c, lbl_805A0434 + 0x344c);
        }
        snprintf(buf, 0x7f, base + 0x8b8, lbl_805A0434 + 0x344c);
        *(int*)(lbl_805A0434 + 0x3490) = 0;
        *(int*)(lbl_805A0434 + 0x348c) = 0;
        lbl_805A0434[0x34ac] &= 0xFFFFFF00;
        {
            int v;
            char* inner = (char*)*(void**)ntFriendInfo::getInstance();
            u32 total = *(u32*)(inner + 8);
            u32 c5 = *(u32*)((char*)*(void**)ntFriendInfo::getInstance() + 0xc);
            if (total != 0) {
                float q = (float)c5 / (float)total;
                v = (int)(lbl_805A2B68 * q);
                if (v > 0x64) {
                    v = 0x64;
                }
            } else {
                v = 0x32;
            }
            netReport(base + 0x81c, v, c5, total);
            *(int*)(lbl_805A0434 + 0x3498) = v;
            int u1 = fn_8033C180(0x65, lbl_8059E7A8, (int*)(lbl_805A0434 + 0x3498));
            netReport(base + 0x8c8, u1, *(int*)(lbl_805A0434 + 0x3498));
            int u2 = fn_8033C180(0x66, lbl_8059E7B0, (int*)(lbl_805A0434 + 0x348c));
            netReport(base + 0x8fc, u2, *(int*)(lbl_805A0434 + 0x348c));
        }
        lbl_805A0434[0x3413] = 1;
        netReport(base + 0x940, lbl_805A0404);
        {
            int rr = fn_80339F84((unsigned char)lbl_805A0404, buf,
                                 (void*)fn_80148A94, 0, 0, 0,
                                 (void*)fn_8014B874, 0, 0, 0, 0);
            if (rr == 0) {
                netReport(base + 0x960);
            }
            r = rr;
        }
        break;
    case 2:
        netReport(base + 0x9a8);
        if (fn_8033CAC0(0x5265C00, 0x5265C00) == 1) {
            fn_8033CAE0(&a20, &a24);
            netReport(base + 0x7e0, a24);
        } else {
            netReport(base + 0x7f0);
        }
        netReport(base + 0x9c0, lbl_805A0404);
        r = fn_8033A0C8((unsigned char)lbl_805A0404,
                        (void*)fn_80148A94, 0,
                        (void*)fn_80148A74, 0, 0, 0, 0);
        if (r == 0) {
            netReport(base + 0x9e0);
        }
        break;
    case 3:
        netReport(base + 0xa1c, lbl_805A0400);
        if (fn_8033CAC0(0x5265C00, 0x5265C00) == 1) {
            fn_8033CAE0(&a18, &a1c);
            netReport(base + 0x7e0, a1c);
        } else {
            netReport(base + 0x7f0);
        }
        lbl_805A0434[0x3413] = 1;
        r = fn_8033A200(lbl_805A0400, (void*)fn_80148A94, 0,
                        (void*)fn_80148A74, 0, 0,
                        lbl_8059E770, 0);
        if (r == 0) {
            netReport(base + 0xa3c);
        }
        break;
    default:
        r = 0;
        break;
    }
    return (r - 1) == 0;
}
