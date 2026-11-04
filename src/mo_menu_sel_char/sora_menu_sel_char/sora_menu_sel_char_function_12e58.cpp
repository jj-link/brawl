#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {

int fn_800C9F14(void* self, int slot);
int fn_800D27A0(void* self, int slot);
int fn_800D2D24(void* self, int slot);
int fn_800D2EB0(void* self, int slot);
int fn_800D3970(void* self, int slot);
extern void* lbl_805A0434;

int fn_10_12E58(void* arg0) {
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4)
        result = 1;
    else
        result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc)
            result = 1;
        else
            result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10)
                r0_4 = 1;
            else
                r0_4 = 0;
            result = 3;
            if (r0_4 != 0)
                result = 2;
        }
    }
    if (result != 2)
        return 0;
    if (*(int*)((char*)arg0 + 0x428) > 0)
        return 2;
    if (*(unsigned char*)((char*)arg0 + 0x426) != 0)
        return 1;
    void* task = g_muWifiInterfaceTask;
    if (fn_800C9F14(task, *(int*)((char*)arg0 + 0x1b0)) == 0)
        return 0;
    if (fn_800D3970(task, *(int*)((char*)arg0 + 0x1b0)) != 0)
        return 5;
    if (fn_800D27A0(task, *(int*)((char*)arg0 + 0x1b0)) >= 0)
        return 5;
    if (*(unsigned char*)((char*)arg0 + 0x425) != 0)
        return 4;
    if (fn_800D2EB0(task, *(int*)((char*)arg0 + 0x1b0)) != 0)
        return 7;
    if (fn_800D2D24(task, *(int*)((char*)arg0 + 0x1b0)) == 0 || *(int*)((char*)lbl_805A0434 + 0x3408) >= 0x40)
        return 6;
    return 3;
}
}
