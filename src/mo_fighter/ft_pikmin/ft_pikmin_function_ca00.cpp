#include <types.h>
#pragma force_active on

struct PikminPairMember {
    u32 storage[2];
};

struct PikminPairArray {
    u32 header;
    PikminPairMember members[];
};

extern "C" PikminPairMember* fn_113_CA00(PikminPairArray* array, int index) {
    return &array->members[index];
}
