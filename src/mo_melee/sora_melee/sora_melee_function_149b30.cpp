#pragma force_active on
extern char lbl_27_bss_3210[];

extern "C" {
void* fn_27_149B30() {
    char* p = *(char**)(lbl_27_bss_3210 + 0x6c);
    return *(void**)(p + 0x94);
}
}
