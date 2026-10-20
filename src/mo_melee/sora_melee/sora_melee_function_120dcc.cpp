#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern void* g_ftSlotManager;
extern u32 lbl_27_bss_31F8;
extern "C" int fn_27_144FC4(u32, void*, int);

extern "C" int fn_27_120DCC(char* self) {
    char* e;
    u8 count = *(u8*)(self + 0x158);
    u8 i = 0;
    for (; i < count; i++) {
        e = self + i * 0x54;
        if (*(u32*)(e + 0xC) & 0x1000) {
            u32 idx = *(u32*)(e + 0x8);
            void* slot = *(void**)((char*)g_ftSlotManager + 0x154 + idx * 4);
            return fn_27_144FC4(lbl_27_bss_31F8, slot, 0);
        }
    }
    return 0;
}
