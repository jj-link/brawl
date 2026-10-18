#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct FloatTableAccesser {
    u8 prefix[0x10];
    u32 indexBase;         // 0x10: first index served by the pointer table
    u8 gap[0x4];           // 0x14: not accessed by this lookup
    float* floatArrays[1]; // 0x18: inline, variable-length table of float arrays
};

extern "C" {
float fn_95_17700(FloatTableAccesser* self, void* accesser, int index, int element)
{
    return self->floatArrays[index - self->indexBase][element];
}
}
