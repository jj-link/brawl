#include <stddef.h>
#pragma force_active on

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct FtWorkMul {
    u8 pad[0xc];
    s32 *m_intWorks;
} FtWorkMul;

extern "C" void fn_110_9998(FtWorkMul *work, s32 value, u32 index) {
    work->m_intWorks[index] *= value;
}
