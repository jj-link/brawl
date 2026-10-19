#include <types.h>
#pragma force_active on

struct LucasPairMember {
    u32 storage[2];
};

struct LucasPairArray {
    u32 header;
    LucasPairMember members[2];
};

extern "C" void fn_27_57F78(LucasPairMember* member);

extern "C" void fn_115_A0D0(LucasPairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
