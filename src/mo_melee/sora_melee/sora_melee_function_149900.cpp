#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];

void* fn_27_149900(void) {
    char* p = *(char**)(lbl_27_bss_3210 + 0xd8);
    return *(void**)(p + 0xa0);
}
}
