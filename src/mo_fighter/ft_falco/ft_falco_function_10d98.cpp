#pragma force_active on
struct FalcoAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[4];
    int* rows[1];
};

extern "C" int fn_108_10D98(FalcoAccesser* self, void*, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
