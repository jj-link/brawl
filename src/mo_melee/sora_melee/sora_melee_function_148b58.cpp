#pragma force_active on
extern char lbl_27_bss_3210[];

extern "C" void *fn_27_148B58(void) {
    char *p = *(char **)(lbl_27_bss_3210 + 0x30);
    return *(void **)(p + 0x9c);
}
