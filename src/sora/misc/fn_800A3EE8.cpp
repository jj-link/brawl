#include <types.h>
#pragma force_active on

extern "C" {
    extern void* g_gfPadSystem;
    int getDebugPadStatus__11gfPadSystemFiP11gfPadStatus(void* self, int port, void* out);

    void fn_800A3EE8(char* p) {
        u8 status[0x40];
        int i = 0;
        do {
            getDebugPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, i, status);
            if (*(u32*)(status + 4) & 8) {
                *(int*)(p + 0xc) = i;
                break;
            }
            i++;
        } while (i < 8);

        {
            u32 idx = *(u32*)(p + 0xc);
            char* base = p + (idx << 5);
            float v = *(float*)(base + 0x2c);
            char* q = *(char**)p;
            *(float*)(q + 0xcc) = v;
            *(u16*)(q + 0xfa) = *(u16*)(q + 0xfa) | 0x80;
        }
    }
}
