#include <types.h>
#pragma force_active on

struct Entry {
    void* m_0;
    void* m_4[2];
};

extern "C" {
    extern Entry lbl_27_bss_3210[];
    extern void* g_ftSlotManager;
    extern char lbl_27_data_2BBD8[];
    void* fn_27_1222C8(void* self, u32 index);
    void* getManager__11soArchiveDbFUl(u32 id);
    void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
}

extern "C" void* fn_27_148DA4(void* unused, s32 kind) {
    switch (kind) {
    case 8: {
        void* p = lbl_27_bss_3210[kind].m_0;
        return *(void**)((char*)p + 0x94);
    }
    case 5: {
        void* p = fn_27_1222C8(g_ftSlotManager, 8);
        void* addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(getManager__11soArchiveDbFUl(0), (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)((char*)addr + 0x10);
    }
    default:
        return 0;
    }
}
