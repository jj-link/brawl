#pragma force_active on
namespace {
struct PikminAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x3C - 0x18];
    void** rows[1];
};
}

extern "C" void* fn_113_2A050(PikminAccesser* self, void*, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
