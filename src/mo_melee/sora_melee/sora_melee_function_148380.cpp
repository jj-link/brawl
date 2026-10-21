#include <types.h>
#pragma force_active on

extern char lbl_27_bss_3210[];
extern void* g_ftSlotManager;
extern "C" void* fn_27_1222C8(void* self, u32 index);
extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
extern char lbl_27_data_2BBD8[];

extern "C" void* fn_27_148380(void* unused, int kind) {
    switch (kind) {
    case 6: {
        void* p = *(void**)(lbl_27_bss_3210 + 0x48);
        return *(void**)((char*)p + 0x9c);
    }
    case 5: {
        void* p = fn_27_1222C8(g_ftSlotManager, 6);
        void* mgr = getManager__11soArchiveDbFUl(0);
        void** addr = (void**)getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return addr[4];
    }
    default:
        return 0;
    }
}
