#pragma force_active on
struct FalcoArticleFloatAccesser {
    unsigned char prefix[0x10];
    unsigned int indexBase;
    unsigned char gap[0x4];
    float* floatArrays[1];
};

extern "C" float fn_108_10D78(FalcoArticleFloatAccesser* self, void* accesser, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
