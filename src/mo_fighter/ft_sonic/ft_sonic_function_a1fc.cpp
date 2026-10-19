#include <types.h>
#pragma force_active on

struct PairMember {
    u32 storage[2];
};

struct PairArray {
    u32 header;
    PairMember members[2];
};

extern "C" void fn_27_57F78(PairMember* member);

extern "C" void fn_123_A1FC(PairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
