#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct LucasSampleTable {
    u32 unknown[4];
    s32 first;
};

extern "C" float fn_114_19AC4(
    LucasSampleTable* table,
    s32 unused,
    s32 index,
    s32 sample
) {
    char* entry = (char*)table + (index - table->first) * 4;
    float* values = *(float**)(entry + 24);
    return values[sample];
}
