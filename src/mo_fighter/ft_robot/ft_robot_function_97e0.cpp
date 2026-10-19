#include <types.h>
#pragma force_active on

struct FtRobotPairMember {
    u32 storage[2];
};

struct FtRobotPairArray {
    u32 header;
    FtRobotPairMember members[2];
};

extern "C" void fn_27_57F78(FtRobotPairMember* member);

extern "C" {
void fn_120_97E0(FtRobotPairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
}
