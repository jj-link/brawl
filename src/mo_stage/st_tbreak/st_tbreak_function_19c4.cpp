#pragma force_active on
extern "C" const float lbl_89_rodata_64;

extern "C" int fn_89_19C4(void* unused, float* self) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_89_rodata_64 + result);
    self[0] = *value;
    self[1] = *value;
    self[2] = *value;
    return result;
}
