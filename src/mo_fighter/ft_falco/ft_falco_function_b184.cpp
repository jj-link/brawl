#include <types.h>
#pragma force_active on

struct FtWorkBuf {
    char pad[0x1c];
    u32* m_flagWorks;
};

extern "C" void fn_108_B184(FtWorkBuf* work, u32 mask, u32 index) {
    work->m_flagWorks[index] &= ~mask;
}
