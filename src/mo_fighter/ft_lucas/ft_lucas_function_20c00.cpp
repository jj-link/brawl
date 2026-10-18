#pragma force_active on
typedef unsigned int u32;

struct LucasFloatTable {
    unsigned char padding[0x10];
    u32 firstIndex;
    unsigned char padding2[4];
    float* rows[1];
};

extern "C" float fn_114_20C00(LucasFloatTable* table, int unused, u32 row, u32 column) {
    return table->rows[row - table->firstIndex][column];
}
