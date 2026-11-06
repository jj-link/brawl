#include <types.h>
#pragma force_active on

extern "C" {
    extern void* g_GameGlobal;
    extern u8* g_IfAdvMngr;
    void* fn_800DFC68();
    void fn_8010C0C4(void* a, void* b);
    void fn_8010C0DC(void* a, void* b);
}

extern "C" void fn_27_245034(u8* self) {
    *(s32*)(self + 0x48) = 1;
    u8* p = *(u8**)((u8*)g_GameGlobal + 0x30);
    if ((s8)p[0x5fa] >= 1 && !((p[0x606] >> 7) & 1)) {
        u8* mgr = g_IfAdvMngr;
        if (mgr) {
            mgr[0x48] |= 0x40;
            if (*(void**)(mgr + 0x104)) {
                if ((((u32)mgr[0x48] >> 6) & 1u) == 1u) {
                    void* r = fn_800DFC68();
                    fn_8010C0C4(*(void**)(mgr + 0x104), r);
                } else {
                    void* r = fn_800DFC68();
                    fn_8010C0DC(*(void**)(mgr + 0x104), r);
                }
            }
        }
    }
}
