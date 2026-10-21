#pragma force_active on
typedef unsigned long u32;
typedef unsigned short u16;
typedef int s32;

extern "C" {
    void* fn_27_1222C8(void* self, u32 index);
    void* getManager__11soArchiveDbFUl(u32);
    void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);
    extern char lbl_27_data_2BBD8[];
    extern char lbl_27_bss_3210[];
    extern void* g_ftSlotManager;
}

extern "C" s32 fn_27_1489B8(s32 unused, s32 kind) {
    switch (kind) {
    case 0x1b: {
        char* p = *(char**)(lbl_27_bss_3210 + 0x144);
        return *(s32*)(p + 0x94);
    }
    case 5: {
        void* slot = fn_27_1222C8(g_ftSlotManager, 0x1b);
        void* mgr = getManager__11soArchiveDbFUl(0);
        char* addr = (char*)getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)slot, lbl_27_data_2BBD8, 0, 0, -1);
        return *(s32*)(addr + 0x10);
    }
    default:
        return 0;
    }
}
