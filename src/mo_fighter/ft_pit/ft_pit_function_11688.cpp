#pragma force_active on
struct PitArticleFloatAccesser {
    unsigned char prefix[0x10];
    unsigned int indexBase;
    unsigned char gap[0x4];
    float* floatArrays[1];
};

extern "C" float fn_112_11688(PitArticleFloatAccesser* self, void*, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
