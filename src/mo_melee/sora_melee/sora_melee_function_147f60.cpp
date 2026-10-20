#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];

void* fn_27_147F60(void) {
    char* p = *(char**)(lbl_27_bss_3210 + 0x228);
    return *(void**)(p + 0x98);
}
}
