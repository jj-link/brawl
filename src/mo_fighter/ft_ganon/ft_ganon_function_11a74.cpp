#pragma force_active on
typedef unsigned int u32;

struct GanonFloatAccesser {
    unsigned char prefix[0x10];
    u32 indexBase;
    unsigned char gap[0x4];
    float* floatArrays[1];
};

extern "C" float fn_109_11A74(
    GanonFloatAccesser* self,
    void* accesser,
    int index,
    int element
) {
    return self->floatArrays[index - self->indexBase][element];
}
