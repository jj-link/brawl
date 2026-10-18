#include <types.h>
#pragma force_active on

namespace {
struct ArticleIntAccesser {
    u8 prefix[0x14];
    int indexBase;
    u8 gap[0x14];
    int* intArrays[1];
};
} // namespace

extern "C" int fn_122_20568(ArticleIntAccesser* self, void* accesser, int index, int element) {
    return self->intArrays[index - self->indexBase][element];
}
