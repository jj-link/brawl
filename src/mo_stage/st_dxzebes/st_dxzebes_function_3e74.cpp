#pragma force_active on
extern "C" const float lbl_84_rodata_28;

extern "C" int fn_84_3E74(void* self, float* output)
{
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_84_rodata_28 + result);
    output[0] = *value;
    output[1] = *value;
    output[2] = *value;
    return result;
}
