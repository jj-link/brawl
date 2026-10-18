#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_85800(void);
extern "C" void __register_global_object(void *object, void *destructor, void *chain);

extern "C" u8 lbl_27_bss_1538;
extern "C" unsigned char lbl_27_bss_153C[0x14];
extern "C" unsigned char lbl_27_bss_F8C[0xC];

extern "C" void *fn_27_85840(void)
{
    if ((signed char)lbl_27_bss_1538 == 0) {
        __register_global_object(lbl_27_bss_153C,
                                  (void *)fn_27_85800,
                                  lbl_27_bss_F8C);
        lbl_27_bss_1538 = 1;
    }
    return lbl_27_bss_153C;
}
