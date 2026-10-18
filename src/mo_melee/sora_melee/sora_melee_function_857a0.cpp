#pragma force_active on
typedef unsigned char u8;

extern u8 lbl_27_bss_1520;
extern unsigned char lbl_27_bss_1524[0x14];
extern unsigned char lbl_27_bss_F80[0xC];

extern "C" void fn_27_85800();
extern "C" void __register_global_object(void *, void *, void *);

extern "C" void *fn_27_857A0()
{
    if ((signed char)lbl_27_bss_1520 == 0) {
        __register_global_object(lbl_27_bss_1524, (void *)fn_27_85800, lbl_27_bss_F80);
        lbl_27_bss_1520 = 1;
    }
    return lbl_27_bss_1524;
}
