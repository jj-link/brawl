#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];

void* fn_27_148C18(void) {
    char* p = *(char**)(lbl_27_bss_3210 + 0x120);
    return *(void**)(p + 0x94);
}
}
