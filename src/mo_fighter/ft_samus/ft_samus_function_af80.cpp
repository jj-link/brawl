#include <types.h>
#pragma force_active on

extern "C" const float lbl_94_rodata_C;

struct FtSamusFloatWorkHolder {
    u8 pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_94_AF80(FtSamusFloatWorkHolder* work, u32 index, float value) {
    if (lbl_94_rodata_C != value) {
        work->m_floatWorks[index] /= value;
    }
}
