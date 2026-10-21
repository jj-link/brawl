#include <types.h>
#pragma force_active on

extern "C" {
u8 fn_27_24D18C();
void fn_27_25A3BC(void*, s32, s32);
s32 fn_800C9E88(s32, s32);
void fn_800D0A58(s32, s32, s32);
}

extern s32 g_muWifiInterfaceTask;

extern "C" void fn_27_25A300(u8* self) {
    s32 task = g_muWifiInterfaceTask;
    u8 idx = fn_27_24D18C();

    if (idx == 0xFF) {
        idx = 4;
    }

    ((u8*)(task + idx * 0x218))[0xC5] = 3;
    fn_800D0A58(task, 0, 0xFE);

    for (s32 i = 0; i < *(s32*)(self + 0x168); ++i) {
        if (fn_800C9E88(task, i) == 0) {
            fn_27_25A3BC(self, i, 1);
        }
    }

    self[0x14F] = 1;
}
