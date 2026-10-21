#include <types.h>
#pragma force_active on

struct gfPadStatus {
    u8 _pad0[4];
    u32 flags;
    u8 _rest[0x38];
};

extern void* g_gfPadSystem;
extern "C" void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, gfPadStatus*);

extern "C" void fn_10_1B794(void* self) {
    u8* base = (u8*)self;
    int port = *(int*)(*(u8**)(base + 0x9c) + 0x1dc);
    if (port < 0) {
        *(int*)(base + 0xc8) = 0;
        return;
    }
    int v = *(int*)(base + 0xa4) - 4;
    if ((u32)v <= 4) {
        *(int*)(base + 0xc8) = 0;
        return;
    }
    gfPadStatus status;
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, port, &status);
    if (status.flags & 0x200) {
        *(int*)(base + 0xc8) = *(int*)(base + 0xc8) + 1;
    } else {
        *(int*)(base + 0xc8) = 0;
    }
}
