#pragma force_active on
struct LucasIndexedValues {
    unsigned char pad0[0x14];
    int baseIndex;
    unsigned char pad1[0x0C];
    unsigned int* values[1];
};

extern "C" unsigned int fn_114_1E574(
    LucasIndexedValues* self,
    int unused,
    int index,
    int subindex)
{
    return self->values[index - self->baseIndex][subindex];
}
