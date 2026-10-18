#pragma force_active on
struct KirbyAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char padding[0x10];
    int* rows[1];
};

extern "C" int fn_96_23E40(KirbyAccesser* self, void*, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
