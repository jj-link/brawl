#pragma force_active on
#include <mu/wifi/mu_wifi_interface.h>
#include <ip/ip_switch.h>

struct SoraInner {
    unsigned char pad0[0x13];
    unsigned char b13;
    unsigned char b14;
};

struct SoraSelf {
    unsigned char pad0[0x44];
    SoraInner* inner;
    unsigned char pad48[0x11B - 0x48];
    unsigned char b11B;
    unsigned char pad11C[4];
    int result;
    unsigned char b124;
};

struct SoraBssObj {
    unsigned char pad0[0xD5];
    unsigned char bD5;
};

extern "C" {
void OSReport(const char*, ...);
void fn_27_24D450(void* self, int* count);
void fn_8004A914(void* p, int v);
void fn_800CCEC4(void* p, int v);
void fn_800CC1A4(void* p, unsigned int a, unsigned int b);
int fn_800CC1BC(void* p);
extern char lbl_27_data_534F0[];
extern char lbl_27_data_53530[];
extern SoraBssObj* lbl_27_bss_59A8;
}

extern "C" int fn_27_258D18(SoraSelf* self) {
    if (self->result != 0) {
        return 1;
    }
    muWifiInterfaceTask* task = g_muWifiInterfaceTask;
    int r = fn_800CC1BC(task);
    self->result = r;
    if (r == 0 && self->b11B != 0 && self->b124 != 0) {
        int flag = 0;
        int fd5 = ((unsigned char*)task)[0xFD5];
        if (fd5 <= 1) {
            OSReport(lbl_27_data_534F0, fd5);
            flag = 1;
        }
        SoraInner* inner = self->inner;
        if (inner->b14 == 0 && inner->b13 == 1) {
            SoraBssObj* p = lbl_27_bss_59A8;
            if (p != 0 && p->bD5 != 0) {
                int count;
                fn_27_24D450(p, &count);
                if (count <= 1) {
                    OSReport(lbl_27_data_53530, count);
                    flag = 1;
                }
            }
        }
        if (flag != 0) {
            fn_800CCEC4(task, 0);
            fn_8004A914(ipSwitch::getInstance(), 0);
            self->result = 2;
            fn_800CC1A4(task, 0xE, 2);
        }
    }
    return self->result != 0;
}
