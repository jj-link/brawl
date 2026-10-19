#pragma force_active on
extern "C" bool fn_41_1AE7C(void* p);
extern float lbl_41_rodata_C9C;

extern "C" {
bool fn_41_1CB78(void* unit) {
    if (fn_41_1AE7C(unit) == 1) {
        return false;
    }
    return lbl_41_rodata_C9C == *(float*)((char*)unit + 0x4c);
}
}
