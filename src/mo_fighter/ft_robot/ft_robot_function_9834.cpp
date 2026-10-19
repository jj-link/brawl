#include <types.h>
#pragma force_active on

struct RobotPairMember {
    u32 storage[2];
};

struct RobotPairArray {
    u32 header;
    RobotPairMember members[2];
};

extern "C" void fn_27_57ED8(RobotPairMember* member, void* argument);

extern "C" void fn_120_9834(RobotPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
