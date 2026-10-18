#pragma force_active on
extern "C" unsigned char lbl_96_data_B460[];

extern "C" void fn_96_15BA8(void *object)
{
    *(void **)object = (void *)&lbl_96_data_B460[0];
}
