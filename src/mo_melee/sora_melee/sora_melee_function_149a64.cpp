#pragma force_active on
typedef unsigned long u32;
typedef unsigned short u16;

extern "C" {
extern void* g_ftSlotManager;
extern char lbl_27_data_2BBD8[];
extern char lbl_27_bss_3210[];

void* fn_27_1222C8(void*, u32);
void* getManager__11soArchiveDbFUl(u32);
void* getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(
    void*, u32, const char*, u16, u32, u32);

void* fn_27_149A64(void*, int kind) {
    if (kind == 5) {
        void* slot = fn_27_1222C8(g_ftSlotManager, 0x29);
        void* manager = getManager__11soArchiveDbFUl(0);
        char* data = (char*)getPublicAddress__16utArchiveManagerFUlPCcUsUlUl(
            manager, (u32)slot, lbl_27_data_2BBD8, 0, 0, -1);
        return *(void**)(data + 0x14);
    }

    switch (kind) {
    case 0x29:
        return *(void**)(*(char**)(lbl_27_bss_3210 + 0x1EC) + 0xB8);
    default:
        return 0;
    }
}
}
