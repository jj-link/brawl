#include <types.h>
#pragma force_active on

struct DiddyPairMember {
    u32 storage[2];
};

struct DiddyPairArray {
    u32 header;
    DiddyPairMember members[2];
};

extern "C" void fn_27_57ED8(DiddyPairMember* member, void* argument);

extern "C" void fn_115_A124(DiddyPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
