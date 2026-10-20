#pragma force_active on
extern char lbl_27_bss_3210[];

extern "C" {
void* fn_27_14836C() {
    char* p = *(char**)(lbl_27_bss_3210 + 0x9c);
    return *(void**)(p + 0xa0);
}
}
