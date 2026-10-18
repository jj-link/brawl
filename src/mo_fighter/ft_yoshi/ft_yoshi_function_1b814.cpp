#pragma force_active on
namespace {
struct DededeAccesserRows {
    unsigned char prefix[0x14];
    int firstIndex;              // +0x14
    unsigned char unused[0x28 - 0x18];
    int* rows[33];               // +0x28: rows[index - firstIndex]
};
} // namespace

extern "C" int fn_95_1B814(DededeAccesserRows* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
