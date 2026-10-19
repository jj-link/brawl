#include <types.h>
#pragma force_active on

struct FtPairMember {
    u32 storage[2];
};

struct FtPairArray {
    u32 header;
    FtPairMember members[2];
};

extern "C" void fn_27_57F78(FtPairMember* member);

extern "C" void fn_97_B0E8(FtPairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
