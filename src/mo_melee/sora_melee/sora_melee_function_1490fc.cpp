#include <types.h>
#pragma force_active on

struct Entry {
    void* m_0;
    void* m_4;
    void* m_8;
};

extern "C" {
    extern Entry lbl_27_bss_3210[];
    extern void* g_ftSlotManager;
    extern char lbl_27_data_2BBD8[];

    void* fn_27_1222C8(void* self, u32 index);
    void* getManager__11soArchiveDbFUl(u32);
    void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(
        void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
}

extern "C" void* fn_27_1490FC(void* unused, s32 kind) {
    switch (kind) {
    case 0x17:
        return *(void**)((char*)lbl_27_bss_3210[kind].m_0 + 0xA4);
    case 5: {
        void* p = fn_27_1222C8(g_ftSlotManager, 0x17);
        void* mgr = getManager__11soArchiveDbFUl(0);
        void* addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(
            mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)((char*)addr + 0x14);
    }
    default:
        return 0;
    }
}
