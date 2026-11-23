#pragma force_active on
extern "C" const float lbl_65_rodata_0[];

extern "C" int fn_65_6974(void* self, float* out)
{
    int result = 0;
    const float* value = (const float*)((const char*)lbl_65_rodata_0 + result);
    out[0] = *value;
    out[1] = *value;
    out[2] = *value;
    return result;
}
