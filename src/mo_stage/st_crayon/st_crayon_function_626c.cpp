#pragma force_active on
extern "C" {
extern unsigned char lbl_56_bss_F0[];
extern unsigned char lbl_56_bss_F8[];
extern const float lbl_56_rodata_98;
extern void fn_56_36B4();
extern unsigned char lbl_56_bss_5C[];
extern void *__register_global_object(void *, void *, void *);
}

extern "C" void *fn_56_626C() {
    if (*(signed char *)lbl_56_bss_F0 == 0) {
        unsigned char *object = lbl_56_bss_F8;
        unsigned int value = *(unsigned int *)(object + 0x38);

        *(float *)(object + 0x24) = lbl_56_rodata_98;
        *(float *)(object + 0x28) = lbl_56_rodata_98;
        *(float *)(object + 0x2C) = lbl_56_rodata_98;
        *(unsigned int *)(object + 0x38) = value & ~31u;

        __register_global_object(object, (void *)fn_56_36B4, lbl_56_bss_5C);
        *lbl_56_bss_F0 = 1;
    }

    return lbl_56_bss_F8;
}
