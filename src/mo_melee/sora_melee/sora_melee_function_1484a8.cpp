#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];

void* fn_27_1484A8(void) {
    char* p = *(char**)(lbl_27_bss_3210 + 0x48);
    return *(void**)(p + 0xa4);
}
}
