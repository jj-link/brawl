#pragma force_active on
struct LucasValueLookup {
    unsigned char pad[0x10];
    int base;
    unsigned int pad14;
    float* values[1];
};

extern "C" float fn_114_15D50(LucasValueLookup* self, int unused, int index, int subindex) {
    return self->values[index - self->base][subindex];
}
