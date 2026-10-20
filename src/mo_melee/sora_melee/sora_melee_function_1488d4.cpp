#pragma force_active on
extern char lbl_27_bss_3210[];

extern "C" {
void* fn_27_1488D4() {
    char* p = *(char**)(lbl_27_bss_3210 + 0x180);
    return *(void**)(p + 0x9c);
}
}
