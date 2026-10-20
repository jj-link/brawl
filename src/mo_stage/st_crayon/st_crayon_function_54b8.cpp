#pragma force_active on
extern "C" const float lbl_56_rodata_80;

extern "C" unsigned long long fn_56_54B8(void)
{
    float values[2];

    values[0] = lbl_56_rodata_80;
    values[1] = lbl_56_rodata_80;

    return *(unsigned long long*)values;
}
