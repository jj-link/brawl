#include <types.h>
#pragma force_active on

struct LucasPairMember {
    u32 storage[2];
};

struct LucasPairArray {
    u32 header;
    LucasPairMember members[2];
};

extern "C" void fn_27_57ED8(LucasPairMember* member, void* argument);

extern "C" void fn_96_F278(LucasPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
