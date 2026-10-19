#pragma force_active on
struct FtLucarioFloatArrayHolder {
    char pad[0x14];
    float* values;
};

extern "C" const float lbl_118_rodata_C;

extern "C" void fn_118_A428(FtLucarioFloatArrayHolder* obj, int index, float divisor) {
    if (lbl_118_rodata_C == divisor) {
        return;
    }
    obj->values[index] = obj->values[index] / divisor;
}
