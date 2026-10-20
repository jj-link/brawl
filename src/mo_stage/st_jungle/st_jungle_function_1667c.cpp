#include <types.h>
#pragma force_active on

struct FloatArrayHolder {
    unsigned char pad[0x51c];
    float* m_pFloatArray;
};

extern "C" float fn_51_1667C(const FloatArrayHolder* work, u32 index) {
    return work->m_pFloatArray[index];
}
