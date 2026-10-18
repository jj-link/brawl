#pragma force_active on
struct PikminAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char padding[0x108];
    int* rows[1];
};

extern "C" int fn_113_22E18(PikminAccesser* self, void*, int index, int element)
{
    return self->rows[index - self->firstIndex][element];
}
