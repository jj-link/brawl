#include <types.h>
#pragma force_active on

struct FtLucasFloatWork {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_109_925C(FtLucasFloatWork* work, u32 index, float value) {
    work->m_floatWorks[index] *= value;
}
