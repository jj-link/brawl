#pragma force_active on
struct LucasFloatLookup {
    unsigned char unk[16];
    int base;
    unsigned int pad;
    float* values[1];
};

extern "C" float fn_114_1C220(const LucasFloatLookup* self, int unused, int index, int element) {
    return self->values[index - self->base][element];
}
