#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_sndSystem;
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

void fn_24_2388(void* self);
}

void fn_24_2388(void* self) {
    unsigned char* obj = (unsigned char*)self;
    s32 state = *(s32*)(obj + 0x78);
    if (state < 0x12) {
        if (state < 0xF) {
            if (state >= 0xC) {
                goto ret;
            }
            goto play;
        }
        goto play;
    } else {
        if (state >= 0x14) {
            goto play;
        }
        goto ret;
    }
ret:
    return;
play:
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x13, -1, 0, 0, -1);
    obj[0x72] = 0;
    *(s32*)(obj + 0x78) = 0xC;
}
