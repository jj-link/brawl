#pragma force_active on
typedef unsigned char u8;

namespace {
struct DededeArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;
    u8 unused[0x4c - 0x18];
    int* rows[33];
};
} // namespace

extern "C" int fn_104_13260(DededeArticleIntegerAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
