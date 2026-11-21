#pragma force_active on
extern "C" const float lbl_54_rodata_0;

extern "C" int fn_54_2A94(void* unused, float* self) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_54_rodata_0 + result);
    self[0] = *value;
    self[1] = *value;
    self[2] = *value;
    return result;
}
