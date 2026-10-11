#include <types.h>

struct MetaKnightEventHeader {
    s16 flags;
};

extern "C" s32 fn_111_C3A4() {
    return 0;
}

extern "C" void fn_111_C3AC(MetaKnightEventHeader* destination,
                            const MetaKnightEventHeader* header) {
    destination->flags = header->flags;
}
