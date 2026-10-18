#pragma force_active on
struct LinkFloatAccesser {
    unsigned char prefix[0x10];
    unsigned int indexBase;
    unsigned char gap[0x4];
    float* floatArrays[1];
};

extern "C" float fn_93_148C0(LinkFloatAccesser* self, void*, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
