#pragma force_active on
extern "C" unsigned char lbl_96_rodata_D0[];

extern "C" unsigned char* fn_96_1D7B4(int index)
{
    if (index <= -1 || index >= 55)
        return lbl_96_rodata_D0;

    return lbl_96_rodata_D0 + index * 16;
}
