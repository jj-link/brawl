#pragma force_active on
namespace {
struct YoshiArticleIntegerAccesser {
    unsigned char prefix[0x14];
    int firstIndex;                       // +0x14: lowest index served by the table
    unsigned char unused[0x30 - 0x18];
    int* rows[33];                        // +0x30: rows[index - firstIndex]
};
}

extern "C" int fn_95_17720(YoshiArticleIntegerAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
