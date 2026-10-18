#include <types.h>
#pragma force_active on

// Returns element `element` of the row selected by `index - firstIndex`
// from the pointer table at +0x24 of the record.
namespace {
struct YoshiArticleIntegerAccesser {
    u8 prefix[0x14];
    int firstIndex;              // +0x14: lowest index served by the table
    u8 unused[0x24 - 0x18];
    int* rows[1];                // +0x24: rows[index - firstIndex]
};
} // namespace

extern "C" int fn_95_1D8AC(YoshiArticleIntegerAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
