#pragma force_active on
extern "C" unsigned char lbl_96_data_B550[0x40];

extern "C" void fn_96_16150(void **arg3)
{
    arg3[0] = (void *)&lbl_96_data_B550[0];
}
