#pragma force_active on
struct NessScaleTable {
    char pad[0x14];
    float* values;
};

extern "C" void fn_101_D3F4(NessScaleTable* table, int index, float scale) {
    table->values[index] *= scale;
}
