#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_3210[];

void* fn_27_147C74(void) {
    unsigned char* p = *(unsigned char**)(lbl_27_bss_3210 + 0x3c);
    return *(void**)(p + 0x13c);
}
}
