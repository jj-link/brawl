#pragma force_active on
struct LinkAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x3C];
    int* rows[33];
};

extern "C" int fn_93_148E0(LinkAccesser* self, void*, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
