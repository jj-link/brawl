#include <types.h>
#pragma force_active on

struct SnakePairMember {
    u32 storage[2];
};

struct SnakePairArray {
    u32 header;
    SnakePairMember members[2];
};

extern "C" void fn_27_57F78(SnakePairMember* member);

extern "C" void fn_122_F548(SnakePairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
