#pragma force_active on
extern "C" {
extern const float lbl_85_rodata_6C;
int fn_85_53D4(void* self, float* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_85_rodata_6C + result);
    out[0] = *value;
    out[1] = *value;
    out[2] = *value;
    return result;
}
}