#pragma force_active on
typedef unsigned int u32;

extern char lbl_27_bss_3210[];

extern "C" u32 fn_27_147F88() {
    char* p = *(char**)(lbl_27_bss_3210 + 0x228);
    return *(u32*)(p + 0xa0);
}
