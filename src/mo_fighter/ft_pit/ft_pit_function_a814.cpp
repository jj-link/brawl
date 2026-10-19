#include <types.h>
#pragma force_active on

struct FtPairMember {
    u32 storage[2];
};

struct FtPairArray {
    u32 header;
    FtPairMember members[2];
};

extern "C" void fn_27_57ED8(FtPairMember* member, void* argument);

extern "C" void fn_112_A814(FtPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
