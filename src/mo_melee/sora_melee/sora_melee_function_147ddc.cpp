#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

extern void* g_ftSlotManager;
extern char lbl_27_data_2BBD8[];
extern unsigned char lbl_27_bss_3210[];

extern "C" void* fn_27_1222C8(void*, u32);
extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(
    void*, u32, const char*, u16, u32, u32);

extern "C" void* fn_27_147DDC(void*, int kind) {
    if (kind == 5) {
        void* p = fn_27_1222C8(g_ftSlotManager, 2);
        void* mgr = getManager__11soArchiveDbFUl(0);
        char* addr = (char*)getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(
            mgr, (u32)p, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)(addr + 0x10);
    }

    switch (kind) {
    case 2:
        return *(void**)(*(char**)(lbl_27_bss_3210 + 0x18) + 0xB0);
    default:
        return 0;
    }
}
