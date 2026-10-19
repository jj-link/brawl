#include <types.h>
#pragma force_active on

struct SamusPairMember {
    u32 storage[2];
};

struct SamusPairArray {
    u32 header;
    SamusPairMember members[2];
};

extern "C" void fn_27_57ED8(SamusPairMember* member, void* argument);

extern "C" void fn_94_AB28(SamusPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
