#include <types.h>
#pragma force_active on

extern "C" {
    extern char lbl_27_bss_3210[];
    extern void* g_ftSlotManager;
    extern char lbl_27_data_2BBD8[];
    void* fn_27_1222C8(void*, u32);
    void* getManager__11soArchiveDbFUl(u32);
    void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
}

extern "C" void* fn_27_14858C(void*, int kind) {
    switch (kind) {
    case 0x13:
        return *(void**)((char*)*(void**)(lbl_27_bss_3210 + 0xe4) + 0x94);
    case 5: {
        void* p = fn_27_1222C8(g_ftSlotManager, 0x13);
        void* mgr = getManager__11soArchiveDbFUl(0);
        void* addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)((char*)addr + 0x10);
    }
    default:
        return 0;
    }
}
