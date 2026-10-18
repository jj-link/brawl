#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {
extern void fn_800D7C0C(void* a, int b, int c);
extern void fn_800FD96C(int a, int b);
extern void fn_10_145F0(void* self, int a);
extern void fn_10_11C50(void* self);
extern void fn_10_15A84(void* self, int a);
}

extern "C" void fn_10_13854(void* self) {
    char* base = (char*)self;
    fn_800D7C0C(g_muWifiInterfaceTask, *(int*)(base + 0x1b0), 1);
    fn_800FD96C(*(int*)(base + 0x41c), 0);
    int val = 0;
    *(int*)(base + 0x420) = val;
    fn_10_145F0(self, 0x25);
    fn_10_145F0(self, 0x26);
    fn_10_145F0(self, 0x27);
    *(int*)(base + 0x1dc) = -1;
    fn_10_11C50(self);
    *(int*)(base + 0x0) = val;
    fn_10_15A84(self, 2);
}
