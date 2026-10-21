#pragma force_active on
extern "C" void fn_80332BA4(void)
{
    extern void fn_803326EC(void);
    extern unsigned int lbl_805336B0[];
    extern unsigned int lbl_805A0ED0;
    extern unsigned int lbl_805A0F38;

    lbl_805336B0[0] = (unsigned int)&fn_803326EC;
    lbl_805336B0[2] = (unsigned int)&lbl_805A0F38;
    lbl_805336B0[1] = lbl_805A0ED0;
    lbl_805A0ED0 = (unsigned int)lbl_805336B0;
}

__declspec(section ".ctors") extern void* const fn_80332BA4_ctor = (void*)fn_80332BA4;
