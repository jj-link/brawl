#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_bss_3210[];
extern "C" char lbl_27_data_2BBD8[];
extern "C" void* g_ftSlotManager;
extern "C" void* fn_27_1222C8(void* self, u32 index);
extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);

extern "C" u32 fn_27_1496F0(int unused, s32 kind) {
    switch (kind) {
    case 0xB: {
        void* p = *(void**)(lbl_27_bss_3210 + 0x84);
        return *(u32*)((u8*)p + 0x8C);
    }
    case 5: {
        void* slot = fn_27_1222C8(g_ftSlotManager, 0xB);
        void* mgr = getManager__11soArchiveDbFUl(0);
        void* addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)slot, lbl_27_data_2BBD8, 0, 0, -1);
        return *(u32*)((u8*)addr + 0x10);
    }
    default:
        return 0;
    }
}
