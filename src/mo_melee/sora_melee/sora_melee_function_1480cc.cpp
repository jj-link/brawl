#include <types.h>
#pragma force_active on

extern void* g_ftSlotManager;
extern "C" void* fn_27_1222C8(void*, u32);
extern "C" void* getManager__11soArchiveDbFUl(u32 index);
extern "C" int getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
extern "C" char lbl_27_data_2BBD8[];
extern "C" u8 lbl_27_bss_3210[];

extern "C" void* fn_27_1480CC(u32 unused, s32 kind) {
    if (kind == 5) {
        void* p = fn_27_1222C8(g_ftSlotManager, 7);
        void* mgr = getManager__11soArchiveDbFUl(0);
        int addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)(addr + 0x14);
    }
    return *(void**)(*(u32*)(lbl_27_bss_3210 + 0x54) + 0x94);
}
