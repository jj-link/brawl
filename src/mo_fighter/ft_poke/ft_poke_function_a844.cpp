#include <types.h>
#pragma force_active on

extern "C" const float lbl_116_rodata_8;

struct FloatWorkHolder {
    u8 pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_116_A844(FloatWorkHolder* work, float value, u32 index) {
    if (lbl_116_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
