#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1222C8(void*, u32);
extern "C" void* getManager__11soArchiveDbFUl(u32 index);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
extern void* g_ftSlotManager;
extern char lbl_27_data_2BBD8[];
extern char lbl_27_bss_3210[];

extern "C" void* fn_27_1494D0(void* unused, s32 kind) {
    if (kind == 5) {
        void* p = fn_27_1222C8(g_ftSlotManager, 0x21);
        void* mgr = getManager__11soArchiveDbFUl(0);
        void* res = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)((char*)res + 0x10);
    }
    char* base = *(char**)(lbl_27_bss_3210 + 0x18c);
    return *(void**)(base + 0xa0);
}
