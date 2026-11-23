#pragma force_active on
extern "C" const float lbl_80_rodata_0;

extern "C" int fn_80_29D8(int a, float* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_80_rodata_0 + result);
    out[0] = *value;
    out[1] = *value;
    out[2] = *value;
    return result;
}
