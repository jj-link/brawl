#include <types.h>
#include <StaticAssert.h>
#pragma force_active on

struct PairMember {
    u32 storage[2];
};

struct PairArray {
    u32 header;
    PairMember members[2];
};

static_assert(sizeof(PairMember) == 8, "Member stride mismatch");

extern "C" void fn_27_57ED8(PairMember* member, void* argument);

extern "C" void fn_27_384468(PairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
