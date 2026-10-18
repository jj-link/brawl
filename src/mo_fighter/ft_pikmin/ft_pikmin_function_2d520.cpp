#pragma force_active on
struct PikminFloatAccesser
{
    unsigned char prefix[0x10];
    int indexBase;
    unsigned int gap;
    float* floatArrays[1];
};

extern "C" float fn_113_2D520(PikminFloatAccesser* self, void*, int index, int element)
{
    return self->floatArrays[index - self->indexBase][element];
}
