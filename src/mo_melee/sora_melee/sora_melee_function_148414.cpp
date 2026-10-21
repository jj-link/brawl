#include <types.h>
#pragma force_active on

struct ftSlotManager;
extern "C" void* fn_27_1222C8(ftSlotManager* self, u32 index);
extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
extern "C" char lbl_27_data_2BBD8[];
extern "C" ftSlotManager* g_ftSlotManager;

struct Sub {
    u8 pad[0xa0];
    void* m_a0;
};

struct Entry2 {
    u8 pad[0x48];
    Sub* m_48;
};

extern "C" Entry2 lbl_27_bss_3210[];

extern "C" void* fn_27_148414(void* unused, s32 kind) {
    void* result;
    switch (kind) {
    case 6:
        result = lbl_27_bss_3210[0].m_48->m_a0;
        break;
    case 5: {
        void* p = fn_27_1222C8(g_ftSlotManager, 6);
        void* mgr = getManager__11soArchiveDbFUl(0);
        void* addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        result = *(void**)((char*)addr + 0x14);
        break;
    }
    default:
        result = 0;
        break;
    }
    return result;
}
