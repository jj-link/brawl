#pragma force_active on
extern "C" extern const float lbl_27_rodata_860;

extern "C" void fn_27_5EC64(int unused, float *p, float delta)
{
    float v = *p + delta;
    if (v > lbl_27_rodata_860) {
        v = lbl_27_rodata_860;
    }
    *p = v;
}
