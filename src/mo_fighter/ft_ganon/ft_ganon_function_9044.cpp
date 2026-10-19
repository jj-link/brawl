#include <types.h>
#pragma force_active on

struct GanonPairMember {
    u32 storage[2];
};

struct GanonPairArray {
    u32 header;
    GanonPairMember members[2];
};

extern "C" void fn_27_57ED8(GanonPairMember* member, void* argument);

extern "C" void fn_109_9044(GanonPairArray* array, void* argument) {
    for (int i = 0; i < 2; ++i) {
        fn_27_57ED8(&array->members[i], argument);
    }
}
