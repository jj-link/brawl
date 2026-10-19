#include <types.h>
#include <gf/gf_homemenu.h>
#pragma force_active on

extern "C" u32 fn_16_5134(void* self) {
    if (g_gfHomeMenu->setBan(1, 3)) {
        return *(u32*)((char*)self + 0xA4);
    }
    return *(u32*)((char*)self + 0x9C);
}
