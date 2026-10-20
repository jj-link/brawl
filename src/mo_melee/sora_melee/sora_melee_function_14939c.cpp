#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];

void* fn_27_14939C(void) {
    char* p = *(char**)(lbl_27_bss_3210 + 0x24);
    return *(void**)(p + 0xa4);
}
}
