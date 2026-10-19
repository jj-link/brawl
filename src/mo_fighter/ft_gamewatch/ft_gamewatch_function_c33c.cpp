#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

struct FtGwPairMember {
    u32 storage[2];
};

struct FtGwPairArray {
    u32 header;
    FtGwPairMember members[2];
};
static_assert(sizeof(FtGwPairMember) == 8, "Member stride mismatch");
static_assert(sizeof(FtGwPairArray) == 0x14, "Member array layout mismatch");

extern "C" void fn_27_57F78(FtGwPairMember* member);

extern "C" void fn_107_C33C(FtGwPairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
