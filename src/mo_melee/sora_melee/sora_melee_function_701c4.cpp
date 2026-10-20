#pragma force_active on
extern void* lbl_27_bss_120[];

extern "C" void fn_800457F4(void*);

extern "C" void fn_27_701C4(void) {
    int i = 0;
    void** p = lbl_27_bss_120;
    void** end = p + 3;
    while (1) {
        if (*p) {
            fn_800457F4(*p);
        }
        i++;
        p++;
        if (i >= 3) {
            break;
        }
    }
}
