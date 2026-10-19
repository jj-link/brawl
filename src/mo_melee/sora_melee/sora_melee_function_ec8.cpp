#pragma force_active on
extern float lbl_27_rodata_14;
extern float lbl_27_rodata_18;

extern "C" float fn_27_EC8(float x)
{
    if (x > lbl_27_rodata_18) {
        return lbl_27_rodata_18;
    }
    if (x < lbl_27_rodata_14) {
        return lbl_27_rodata_14;
    }
    return x;
}
