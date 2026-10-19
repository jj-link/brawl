#include <types.h>
#pragma force_active on

extern void* g_muWifiInterfaceTask;
extern "C" int fn_800D5C58(void* a, void* b);
extern "C" void fn_10_19374(char* self, int v);

extern "C" {
void fn_10_13464(char* self, int arg) {
    if (fn_800D5C58(g_muWifiInterfaceTask, *(void**)(self + 0x1b0)) != 0) {
        fn_10_19374(self, 2);
        *(int*)(self + 0x42c) = arg;
        *(u8*)(self + 0x426) = 1;
    }
}
}
