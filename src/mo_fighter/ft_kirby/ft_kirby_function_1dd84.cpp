#pragma force_active on
extern "C" int fn_96_1DD84(int index)
{
    if (index <= -1 || index >= 55)
        return -1;

    extern const int lbl_96_rodata_440[];
    return lbl_96_rodata_440[index];
}
