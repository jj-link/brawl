#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];

void* fn_27_147BFC(void) {
    char* p = *(char**)(lbl_27_bss_3210 + 0x3c);
    return *(void**)(p + 0x124);
}
}
