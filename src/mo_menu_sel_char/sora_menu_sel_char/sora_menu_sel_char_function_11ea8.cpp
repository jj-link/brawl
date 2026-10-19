#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_muWifiInterfaceTask;
u32 fn_800D81AC(void* task, s32 val, u8* out);

void fn_10_11EA8(u8* self, u8* out) {
    u8 local;
    u32 r = fn_800D81AC(g_muWifiInterfaceTask, *(s32*)(self + 0x1b0), &local);
    if ((u8)r == 0xff) {
        local = 0xff;
    }
    *out = local;
}
}
