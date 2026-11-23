#pragma force_active on
extern "C" const float lbl_57_rodata_0;

extern "C" int fn_57_37F8(void* self, float* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_57_rodata_0 + result);
    out[0] = *value;
    out[1] = *value;
    out[2] = *value;
    return result;
}