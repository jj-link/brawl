#pragma force_active on
struct FtFloatTable {
    char pad[0x14];
    float *values;
};

extern "C" void fn_117_A778(FtFloatTable *table, int index, float value) {
    table->values[index] -= value;
}
