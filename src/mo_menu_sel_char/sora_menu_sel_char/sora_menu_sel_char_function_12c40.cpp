#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
void fn_10_1915C(void* self, void* arg);
void fn_10_19250(void* self);
void fn_10_19298(void* self, unsigned int v);
unsigned int fn_10_19324(void* self);
void fn_800D2C50(int a, int b, void* c);
void fn_800FD96C(void* self, int v);
void playSE__9sndSystemF5SndIDiiii(void* self, int id, int a, int b, int c, int d);
extern int g_muWifiInterfaceTask;
extern void* g_sndSystem;

void fn_10_12C40(char* self, int arg1, int arg2, int arg3) {
    int sp8[6];
    char* savedSelf = self;
    self = (char*)arg1;
    arg1 = arg2;
    arg2 = *(int*)(savedSelf + 0x41c);
    int wifi = g_muWifiInterfaceTask;
    int a3 = arg3;
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int phase;
    int f;
    unsigned int t;

    if (state >= 0 && state < 4) {
        f = 1;
    } else {
        f = 0;
    }
    if (f != 0) {
        phase = 0;
    } else {
        if (state >= 4 && state < 0xc) {
            f = 1;
        } else {
            f = 0;
        }
        if (f != 0) {
            phase = 1;
        } else {
            if (state >= 0xc && state < 0x10) {
                f = 1;
            } else {
                f = 0;
            }
            phase = 3;
            if (f != 0) {
                phase = 2;
            }
        }
    }

    if (phase == 2) {
        unsigned char* p = *(unsigned char**)(savedSelf + 0x1f4);
        if (p[0x640] == 0) {
            t = self != 0;
            if (t != fn_10_19324(savedSelf)) {
                fn_10_19298(savedSelf, t);
            }
            if (t != 0) {
                fn_800D2C50(wifi, arg1, sp8);
                fn_10_1915C(savedSelf, sp8);
                fn_10_19250(savedSelf);
            }
        }
    }

    switch ((int)self) {
    case 0:
        if (a3 != 0) {
            fn_800FD96C((void*)arg2, 1);
            return;
        }
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2052, -1, 0, 0, -1);
        fn_800FD96C((void*)arg2, 5);
        return;
    case 1:
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2051, -1, 0, 0, -1);
        fn_800FD96C((void*)arg2, 2);
        return;
    case 2:
        fn_800FD96C((void*)arg2, 3);
        return;
    case 3:
        fn_800FD96C((void*)arg2, 4);
        return;
    case 4:
        fn_800FD96C((void*)arg2, 6);
        return;
    }
}
}
