#include <types.h>
#pragma force_active on

extern void* g_ftSlotManager;
extern "C" void* fn_27_1222C8(void*, u32);
extern "C" void* getManager__11soArchiveDbFUl(u32 index);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
extern char lbl_27_data_2BBD8[];
extern char lbl_27_bss_3210[];

extern "C" {
u32 fn_27_1492F8(void*, s32 kind) {
    if (kind == 5) {
        void* p = fn_27_1222C8(g_ftSlotManager, 3);
        void* mgr = getManager__11soArchiveDbFUl(0);
        u32* addr = (u32*)getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return addr[4];
    }
    return *(u32*)(*(u32*)(lbl_27_bss_3210 + 0x24) + 0x9c);
}
}
