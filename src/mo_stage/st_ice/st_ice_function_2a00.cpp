#pragma force_active on
extern "C" const float lbl_62_rodata_0;

extern "C" int fn_62_2A00(void* self, float* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_62_rodata_0 + result);
    out[0] = *value;
    out[1] = *value;
    out[2] = *value;
    return result;
}
