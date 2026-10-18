#include <types.h>
#pragma force_active on

namespace {
struct KirbyAccesser {
    u8 prefix[0x14];
    int firstIndex;
    u8 unused[0x20 - 0x18];
    int* rows[1];
};
}

extern "C" int fn_96_2AE30(KirbyAccesser* self, void*, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
