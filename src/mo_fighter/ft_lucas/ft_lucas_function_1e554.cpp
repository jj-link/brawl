#pragma force_active on
struct LucasValueTable {
    unsigned char pad[0x10];
    int count;
    unsigned int pad14;
    float *values[1];
};

extern "C" float fn_114_1E554(
    LucasValueTable *table,
    int unused,
    int slot,
    int index
) {
    return table->values[slot - table->count][index];
}
