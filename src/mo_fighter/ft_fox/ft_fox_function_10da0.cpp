#pragma force_active on
struct FoxAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[4];
    int* rows[33];
};

extern "C" int fn_97_10DA0(FoxAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
