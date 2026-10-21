#include <types.h>
#pragma force_active on

extern "C" {
extern s32 g_muWifiInterfaceTask;
extern void* g_sndSystem;
s32 fn_800C9C08(s32, s32, s32, s32);
void fn_80075F1C(void*, u32, s32);
void playSE__9sndSystemF5SndIDiiii(void*, s32, s32, s32, s32, s32);

s32 fn_2_3934C(char* self) {
    s32 r30;
    r30 = fn_800C9C08(g_muWifiInterfaceTask, (s32)(self + 0x12C), (s32)(self + 0x130), (s32)(self + 0x134));
    if (r30 != 1) {
        fn_80075F1C(g_sndSystem, *(u32*)(self + 0x144), 0);
        *(s32*)(self + 0x128) = 1;
        if (r30 == 2) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x204F, -1, 0, 0, -1);
            *(s32*)(self + 0x128) = 0;
        }
        if (r30 == 4) {
            *(s32*)(self + 0x128) = 2;
        }
        if (r30 == 3) {
            *(s32*)(self + 0x128) = 1;
        }
        return 6;
    }
    return *(s32*)(self + 0x138);
}
}
