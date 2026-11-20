#include <mu/wifi/mu_wifi_interface.h>
#include <if/if_wifipr_mngr.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" {
int fn_800C9F14(int task);
int fn_800CCEB8(int task);
void fn_800FCC90(IfWifiprMngr* mngr, int idx);
void fn_800FCCA4(IfWifiprMngr* mngr, int idx);
void fn_800FCCB8(IfWifiprMngr* mngr, int idx);
void fn_800FCCCC(IfWifiprMngr* mngr, int idx);
void fn_800FCCE0(IfWifiprMngr* mngr, int idx);
void fn_800FCCF4(IfWifiprMngr* mngr, int idx);
void fn_800FCD08(IfWifiprMngr* mngr, int idx);
}

extern "C" int fn_27_25A3BC(char* base, int idx, int flag) {
    IfWifiprMngr* mngr;
    int task = (int)g_muWifiInterfaceTask;
    mngr = g_IfWifiprMngr;
    int* slot;
    int state = fn_800C9F14(task);
    if (state == 0 && fn_800CCEB8(task) != 0) {
        state = 5;
    }
    if (flag == 0 && (slot = (int*)(base + idx * 4 + 0x11c), state == *(int*)(base + idx * 4 + 0x11c))) {
    } else {
        *(int*)(base + idx * 4 + 0x11c) = state;
        slot = (int*)(base + idx * 4 + 0x11c);
        switch (state) {
        case 0:
            if (flag != 0) {
                fn_800FCCA4(mngr, idx);
            } else {
                fn_800FCCF4(mngr, idx);
                g_sndSystem->playSE((SndID)0x2052, -1, 0, 0, -1);
            }
            break;
        case 1:
            fn_800FCCB8(mngr, idx);
            g_sndSystem->playSE((SndID)0x2051, -1, 0, 0, -1);
            break;
        case 2:
            fn_800FCCCC(mngr, idx);
            break;
        case 3:
            fn_800FCCE0(mngr, idx);
            break;
        case 4:
            fn_800FCD08(mngr, idx);
            break;
        case 5:
            fn_800FCC90(mngr, idx);
            break;
        }
    }
    return *slot != 0;
}
