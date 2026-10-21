#include <types.h>
#pragma force_active on

extern "C" void fn_80073F84(void*, int);
extern "C" void fn_80076C78(void*);
extern "C" void fn_7_AC0(void*);
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern void* g_sndSystem;

extern "C" void fn_7_A14(void* p) {
    u8* self = (u8*)p;
    *(s32*)(*(u8**)(self + 0x1ac) + 0x1bf4) = 1;
    *(s32*)(*(u8**)(self + 0x1ac) + 0x1d14) = 0x20;
    fn_80073F84(g_sndSystem, 0x1e);
    fn_80076C78(g_sndSystem);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x16, -1, 0, 0, -1);
    *(u8*)(*(u8**)(self + 0x1ac) + 0x1d18) = 0;
    fn_7_AC0(self);
}
