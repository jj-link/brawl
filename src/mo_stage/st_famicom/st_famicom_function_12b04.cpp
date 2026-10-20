#include <types.h>
#pragma force_active on

typedef struct {
    u8 _0[0x51c];
    float* m_floatWorks;
} FamicomWork;

extern "C" float fn_68_12B04(const FamicomWork* work, u32 index) {
    return work->m_floatWorks[index];
}
