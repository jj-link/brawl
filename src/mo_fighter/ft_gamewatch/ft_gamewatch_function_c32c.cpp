#include <types.h>
#pragma force_active on

struct PairMember {
    u32 storage[2];
};

struct PairArray {
    u32 header;
    PairMember members[4];
};

extern "C" PairMember* fn_107_C32C(PairArray* array, int index) {
    return &array->members[index];
}
