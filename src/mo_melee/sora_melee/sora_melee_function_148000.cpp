#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_bss_3210[0x298];
}

extern "C" u32 fn_27_148000() {
    char* p = *(char**)(lbl_27_bss_3210 + 0x228);
    return *(u32*)(p + 0xB8);
}
