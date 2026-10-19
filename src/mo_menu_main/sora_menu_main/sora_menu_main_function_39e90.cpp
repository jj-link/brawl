#include <types.h>
#pragma force_active on

extern "C" void* g_muWifiInterfaceTask;

struct MuWifiInterfaceObj {
    u8 prefix[0x1f1];
    u8 flag1f1;
};

extern "C" void fn_2_39E90(MuWifiInterfaceObj* obj) {
    obj->flag1f1 = 0;
    if (g_muWifiInterfaceTask != 0) {
        obj->flag1f1 = 1;
    }
}
