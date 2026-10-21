#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1222C8(void* self, u32 index);
extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
extern "C" char lbl_27_data_2BBD8[];
extern "C" char lbl_27_bss_3210[];
extern void* g_ftSlotManager;

extern "C" void* fn_27_148E54(void* unused, s32 kind) {
    switch (kind) {
    case 0x1a: {
        char* p = *(char**)(lbl_27_bss_3210 + 0x138);
        return *(void**)(p + 0x98);
    }
    case 0x5: {
        void* slot = fn_27_1222C8(g_ftSlotManager, 0x1a);
        void* mgr = getManager__11soArchiveDbFUl(0);
        char* addr = (char*)getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)slot, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)(addr + 0x10);
    }
    default:
        return 0;
    }
}
