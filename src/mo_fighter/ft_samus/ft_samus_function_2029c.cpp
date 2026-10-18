#pragma force_active on
struct SamusArticleFloatAccesser {
    unsigned char prefix[0x10];
    unsigned int indexBase;
    unsigned char gap[0x4];
    float* floatArrays[1];
};

extern "C" float fn_94_2029C(
    SamusArticleFloatAccesser* self,
    void* unused,
    int index,
    int element
) {
    return self->floatArrays[index - self->indexBase][element];
}
