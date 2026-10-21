#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1222C8(void*, u32);
extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" int getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
extern "C" char lbl_27_data_2BBD8[];
extern "C" char lbl_27_bss_3210[];
extern "C" void* g_ftSlotManager;

extern "C" void* fn_27_148620(int unused, s32 kind) {
    switch (kind) {
    case 0x13:
        {
            void* p = *(void**)(lbl_27_bss_3210 + 0xe4);
            return *(void**)((char*)p + 0x98);
        }
    case 0x5:
        {
            void* slot = fn_27_1222C8(g_ftSlotManager, 0x13);
            void* mgr = getManager__11soArchiveDbFUl(0);
            int addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)slot, lbl_27_data_2BBD8, 0, 0, -1);
            return *(void**)((char*)addr + 0x14);
        }
    default:
        return 0;
    }
}
