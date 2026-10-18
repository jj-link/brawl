#pragma force_active on
struct LucasArrayAccessor {
    unsigned char pad0[0x14];
    int base;
    unsigned char pad1[0x14];
    unsigned int* lists[1];
};

extern "C" unsigned int fn_114_19AE4(
    LucasArrayAccessor* self, int, int index, int element
) {
    return self->lists[index - self->base][element];
}
