#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

struct FtPitPairMember {
    u32 storage[2];
};

struct FtPitPairArray {
    u32 header;
    FtPitPairMember members[2];
};
static_assert(sizeof(FtPitPairMember) == 8, "Member stride mismatch");

extern "C" void fn_27_57F78(FtPitPairMember* member);

extern "C" void fn_112_A7C0(FtPitPairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
