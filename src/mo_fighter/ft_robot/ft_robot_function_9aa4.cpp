#include <types.h>
#pragma force_active on

struct FtRobotWork {
    u8 pad[0x14];
    float* m_values;
};

extern "C" void fn_120_9AA4(FtRobotWork* work, u32 index, float value) {
    work->m_values[index] -= value;
}
