#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_bss_3210[];
extern char lbl_27_data_2BBD8[];
extern void* g_ftSlotManager;
void* fn_27_1222C8(void* self, u32 index);
void* getManager__11soArchiveDbFUl(u32);
void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
}

extern "C" void* fn_27_148CE8(void* unused, s32 kind) {
    switch (kind) {
    case 0xe: {
        void* p = *(void**)(lbl_27_bss_3210 + 0xa8);
        return *(void**)((char*)p + 0x94);
    }
    case 5: {
        void* p = fn_27_1222C8(g_ftSlotManager, 0xe);
        void* mgr = getManager__11soArchiveDbFUl(0);
        char* addr = (char*)getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)(addr + 0x14);
    }
    default:
        return 0;
    }
}
