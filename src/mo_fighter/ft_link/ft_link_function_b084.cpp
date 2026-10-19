#include <types.h>
#pragma force_active on

struct B084PairMember {
    u32 storage[2];
};

struct B084PairArray {
    u32 header;
    B084PairMember members[2];
};

extern "C" void fn_27_57ED8(B084PairMember* member, void* argument);

extern "C" void fn_93_B084(B084PairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
