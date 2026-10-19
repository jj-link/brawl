#pragma force_active on
extern const float lbl_70_rodata_48;

extern "C" void fn_70_3B74(char *obj, float delta)
{
    float *val = (float *)(obj + 0x170);
    *val = *val - delta;
    if (*val < lbl_70_rodata_48)
    {
        *val = lbl_70_rodata_48;
    }
}
