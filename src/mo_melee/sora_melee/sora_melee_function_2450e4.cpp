#include <types.h>
#pragma force_active on

extern "C" {
    extern u8* g_IfAdvMngr;
    void* fn_800DFC68();
    void fn_8010C0C4(void* a, void* b);
    void fn_8010C0DC(void* a, void* b);
}

extern "C" void fn_27_2450E4(u8* self) {
    u8* mgr = g_IfAdvMngr;
    if (mgr) {
        mgr[0x48] &= ~0x40;
        if (*(void**)(mgr + 0x104)) {
            u32 flag = (u32)(mgr[0x48] >> 6) & 1u;
            if (flag == 1u) {
                void* r = fn_800DFC68();
                fn_8010C0C4(*(void**)(mgr + 0x104), r);
            } else {
                void* r = fn_800DFC68();
                fn_8010C0DC(*(void**)(mgr + 0x104), r);
            }
        }
    }
    self[0x50] = 0;
}
