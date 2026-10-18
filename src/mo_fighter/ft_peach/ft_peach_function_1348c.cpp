#pragma force_active on
struct PeachFloatTable {
    unsigned char pad[0x10];
    int firstIndex;
    unsigned int reserved;
    float *values[1];
};

extern "C" float fn_103_1348C(PeachFloatTable *table, int unused, int index, int element) {
    return table->values[index - table->firstIndex][element];
}
