#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

struct SamusPairMember {
    u32 storage[2];
};

struct SamusPairArray {
    u32 header;
    SamusPairMember members[2];
};
static_assert(sizeof(SamusPairMember) == 8, "Member stride mismatch");

extern "C" void fn_27_57F78(SamusPairMember* member);

extern "C" void fn_94_AAD4(SamusPairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
