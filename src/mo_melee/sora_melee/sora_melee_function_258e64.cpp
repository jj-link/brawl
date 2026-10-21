#include <types.h>
#pragma force_active on

extern "C" {
u8 fn_27_24D18C();
void fn_800D0A58(s32, s32, s32);
}

extern s32 g_muWifiInterfaceTask;

extern "C" void fn_27_258E64(u8* self) {
    if (self[0x125] != 0) {
        s32 task = g_muWifiInterfaceTask;
        u8 idx = fn_27_24D18C();

        if (idx == 0xFF) {
            idx = 4;
        }

        ((u8*)(task + idx * 0x218))[0xC5] = 4;
        fn_800D0A58(task, 0, 0xFE);
    }

    self[0x11B] = 1;
}
