#pragma force_active on
struct PitAccesser {
    unsigned char unused[0x14];
    int firstIndex;
    unsigned char padding[0x30];
    int* rows[1];
};

extern "C" int fn_112_116A8(PitAccesser* self, void*, int index, int element)
{
    return self->rows[index - self->firstIndex][element];
}
