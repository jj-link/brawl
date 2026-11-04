#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_10_rodata_328[];
int fn_10_99B8(void*);
unsigned fn_800C9F14(void*, int);
int fn_800CA6D4(void*, int);
}

extern "C" int fn_10_E904(void* self) {
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    const unsigned char* entry = lbl_10_rodata_328 + state * 12;
    int b = entry[4];
    if (((b >> 4) & 1) == 0) return 0;
    int result;
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10) r0_4 = 1; else r0_4 = 0;
            result = 3;
            if (r0_4 != 0) result = 2;
        }
    }
    if (result == 2) {
        if (fn_10_99B8(self) == 0) return 0;
        void* task = g_muWifiInterfaceTask;
        int i = 0;
        while (i < *(int*)((char*)self + 0x648)) {
            unsigned a = fn_800C9F14(task, i);
            if ((a - 2) <= 1 && fn_800CA6D4(task, i) == 3) return 0;
            i++;
        }
    }
    return 1;
}