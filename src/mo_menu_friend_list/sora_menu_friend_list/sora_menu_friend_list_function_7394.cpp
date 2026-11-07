#include <gf/gf_task.h>
#include <snd/snd_system.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on
extern "C" {
void fn_800CC604(void*, int);
void fn_800CC7A8(void*, int);
void fn_800CC860(void*, int);
void fn_800CC918(void*, int);
int fn_14_7394(unsigned char* self) {
    unsigned char* task = *(unsigned char**)(self + 0x24ec);
    if (task) {
        if (*(int*)(task + 0x104) == 3) {
            unsigned char flag = task[0x100];
            *(int*)(self + 0x2abc) = *(int*)(task + 0x124);
            ((gfTask*)task)->exit();
            *(unsigned char**)(self + 0x24ec) = 0;
            if (!flag) {
                g_sndSystem->playSE((SndID)6, -1, 0, 0, -1);
                return 2;
            }
        }
        return *(int*)(self + 0x24c4);
    }
    int result;
    if (!self[0x40]) {
        muWifiInterfaceTask* wifi = g_muWifiInterfaceTask;
        switch (*(int*)(self + 0x2a28)) {
        case 0: break;
        case 1: fn_800CC604(wifi, 4); break;
        case 2: fn_800CC7A8(wifi, 2); break;
        case 3: fn_800CC860(wifi, 2); break;
        case 4: fn_800CC918(wifi, 2); break;
        }
    }
    switch (*(int*)(self + 0x2a28)) {
    case 0: break;
    case 1: result = 1; break;
    case 2: result = 2; break;
    case 3: result = 3; break;
    case 4: result = 4; break;
    }
    *(int*)(self + 0x44) = result;
    return 0x21;
}
}