#pragma force_active on
extern "C" const float lbl_117_rodata_C;

struct FtDedeTable {
    char pad[0x14];
    float* values;
};

extern "C" void fn_117_A738(FtDedeTable* obj, int index, float divisor) {
    if (lbl_117_rodata_C == divisor) {
        return;
    }
    obj->values[index] = obj->values[index] / divisor;
}
