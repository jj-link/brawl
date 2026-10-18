#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" void fn_800CCEC4(muWifiInterfaceTask* t, int a);
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

extern "C" void fn_14_6788(void* self) {
    char* base = (char*)self;
    int val;
    if (*(unsigned char*)(base + 0x2a38) != 0) {
        val = *(int*)(base + 0x24d0);
    } else {
        int* p = *(int**)(base + 0x24cc);
        val = p[1];
    }
    fn_800CCEC4(g_muWifiInterfaceTask, 0x64);
    int a5 = *(int*)(base + 0x2a34);
    int a6 = *(int*)(base + 0x24f0);
    int a7 = *(int*)(base + 0x2a1c);
    int res = fn_800BEEB8(0, val, a5, a6, a7, 0x1f, 0, 0x2a, 0x2b, 0, 0, 0xf0);
    *(int*)(base + 0x24ec) = res;
}
