#include <types.h>
#pragma force_active on

struct DonkeyPairMember {
    u32 storage[2];
};

struct DonkeyPairArray {
    u32 header;
    DonkeyPairMember members[2];
};

extern "C" void fn_27_57ED8(DonkeyPairMember* member, void* argument);

extern "C" void fn_92_9848(DonkeyPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
