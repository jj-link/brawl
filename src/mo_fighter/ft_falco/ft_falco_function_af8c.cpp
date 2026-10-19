#include <types.h>
#pragma force_active on

struct PairArray {
    u32 header;
    u32 members[2][2];
};

extern "C" void fn_27_57F78(u32* member);

extern "C" void fn_108_AF8C(PairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(array->members[index]);
    }
}
