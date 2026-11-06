#include <types.h>
#pragma force_active on

extern "C" s32 fn_40_48B24(void*, s32, s32);
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern "C" void setFrameVisible__8MuObjectFf(void*, float);
extern "C" void* g_sndSystem;
extern double lbl_40_rodata_B68;

extern "C" void fn_40_48A44(void* arg0) {
    char* p = (char*)arg0;
    unsigned flags = *(unsigned*)(p + 0x15C);
    if (flags & 0xF) {
        int dir = 2;
        if (flags & 2) {
            dir = 3;
        } else if (flags & 1) {
            dir = 2;
        } else if (flags & 8) {
            dir = 0;
        } else if (flags & 4) {
            dir = 1;
        }
        int result = fn_40_48B24(arg0, *(s32*)(p + 0x50), dir);
        if (result != 7) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
            *(s32*)(p + 0x50) = result;
            setFrameVisible__8MuObjectFf(*(void**)(p + 0x224), (float)result);
        }
    }
}