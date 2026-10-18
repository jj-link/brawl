#pragma force_active on
struct KirbyFloatAccesser {
    unsigned char prefix[0x10];
    unsigned int indexBase;
    unsigned int reserved;
    float* floatArrays[1];
};

extern "C" float fn_96_23E20(KirbyFloatAccesser* self, void* unused, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
