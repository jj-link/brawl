#include <types.h>
#pragma force_active on

struct FloatWorkHolder {
    u8 pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_108_B240(FloatWorkHolder* work, u32 index, float value) {
    work->m_floatWorks[index] = value;
}
