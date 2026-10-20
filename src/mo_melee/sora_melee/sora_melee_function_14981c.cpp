#pragma force_active on
extern "C" {
extern char lbl_27_bss_3210[];
}

extern "C" void *fn_27_14981C(void)
{
    char *p = *(char **)(lbl_27_bss_3210 + 0xc);
    return *(void **)(p + 0x90);
}
