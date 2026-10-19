#include <types.h>
#pragma force_active on

struct FoxPairMember {
    u32 storage[2];
};

struct FoxPairArray {
    u32 header;
    FoxPairMember members[2];
};

extern "C" void fn_27_57ED8(FoxPairMember* member, void* argument);

extern "C" void fn_97_B13C(FoxPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
