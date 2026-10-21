#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

extern "C" char lbl_27_bss_3210[];
extern "C" char lbl_27_data_2BBD8[];
extern "C" void* g_ftSlotManager;
extern "C" void* fn_27_1222C8(void*, u32);
extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(void* self, u32 id, const char* name, u16 a, u32 b, u32 c);

extern "C" void* fn_27_148818(int unused, int kind) {
    switch (kind) {
    case 0x23: {
        char* p = *(char**)(lbl_27_bss_3210 + 0x1a4);
        return *(void**)(p + 0x9c);
    }
    case 5: {
        void* p = fn_27_1222C8(g_ftSlotManager, 0x23);
        void* mgr = getManager__11soArchiveDbFUl(0);
        void* addr = getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)((char*)addr + 0x10);
    }
    default:
        return 0;
    }
}
