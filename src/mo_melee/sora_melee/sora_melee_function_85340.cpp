#pragma force_active on
typedef unsigned char u8;

extern "C" void *__register_global_object(void *object, void *destructor, void *chain);
extern "C" void fn_27_25290();

extern u8 lbl_27_bss_1320[];
extern u8 lbl_27_bss_1328[];
extern u8 lbl_27_bss_F20[];

extern "C" void *fn_27_85340() {
    if ((signed char)lbl_27_bss_1320[0] == 0) {
        __register_global_object(lbl_27_bss_1328, (void *)fn_27_25290, lbl_27_bss_F20);
        lbl_27_bss_1320[0] = 1;
    }
    return lbl_27_bss_1328;
}
