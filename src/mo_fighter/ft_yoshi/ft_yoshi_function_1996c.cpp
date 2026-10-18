#include <types.h>
#pragma force_active on

namespace {
struct YoshiArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;              // +0x14: lowest index served by the table
    u8 unused[0x20 - 0x18];
    int* rows[1];                // +0x20: rows[index - firstIndex]
};
} // namespace

extern "C" int fn_95_1996C(YoshiArticleIntegerAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
