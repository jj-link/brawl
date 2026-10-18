#pragma force_active on
namespace {
struct ArticleIntegerAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x1c - 0x18];
    int* rows[1];
};
} // namespace

extern "C" int fn_125_10CB8(ArticleIntegerAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
