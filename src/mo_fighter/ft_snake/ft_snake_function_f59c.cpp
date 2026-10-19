#include <types.h>
#pragma force_active on

struct SnakePairMember {
    u32 storage[2];
};

struct SnakePairArray {
    u32 header;
    SnakePairMember members[2];
};

extern "C" void fn_27_57ED8(SnakePairMember* member, void* argument);

extern "C" void fn_122_F59C(SnakePairArray* array, void* argument) {
    for (int i = 0; i < 2; ++i) {
        fn_27_57ED8(&array->members[i], argument);
    }
}
