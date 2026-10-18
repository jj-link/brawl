#include <types.h>
#pragma force_active on

struct FtWork {
    u32 m_pad[3];
    s32* m_values;
};

extern "C" void fn_113_CD94(FtWork* work, s32 value, u32 index) {
    work->m_values[index] -= value;
}
