#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1222C8(void* self, u32 index);
extern "C" void* getManager__11soArchiveDbFUl(u32 id);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
extern "C" char lbl_27_bss_3210[];
extern "C" char lbl_27_data_2BBD8[];
extern void* g_ftSlotManager;

extern "C" void* fn_27_148AB0(void* unused, s32 kind) {
    switch (kind) {
    case 4: {
        char* base = *(char**)(lbl_27_bss_3210 + 0x30);
        return *(void**)(base + 0x94);
    }
    case 5: {
        void* p = fn_27_1222C8(g_ftSlotManager, 4);
        void* mgr = getManager__11soArchiveDbFUl(0);
        void* addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)((char*)addr + 0x10);
    }
    default:
        return 0;
    }
}
