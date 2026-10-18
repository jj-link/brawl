#pragma force_active on
struct FloatAccesser
{
    unsigned char prefix[0x10];
    int indexBase;
    unsigned char gap[0x4];
    float* floatArrays[1];
};

extern "C" float fn_107_1F9FC(FloatAccesser* self, void*, int index, int element)
{
    return self->floatArrays[index - self->indexBase][element];
}
