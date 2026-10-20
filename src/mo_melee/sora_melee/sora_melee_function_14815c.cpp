#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern unsigned char lbl_27_bss_3210[];

u32 fn_27_14815C(void) {
    unsigned char* p = *(unsigned char**)(lbl_27_bss_3210 + 0x54);
    return *(u32*)(p + 0x98);
}
}
