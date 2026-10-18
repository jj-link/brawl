#pragma force_active on
struct PitFloatAccesser {
    unsigned char prefix[0x10];
    unsigned int indexBase;
    unsigned int padding;
    float* floatArrays[1];
};

extern "C" float fn_112_16ABC(PitFloatAccesser* self, void* accesser, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
