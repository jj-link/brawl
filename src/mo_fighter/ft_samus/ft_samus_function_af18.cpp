#include <types.h>
#pragma force_active on

struct Work {
    unsigned char pad[0x1c];
    u32* m_flagWorks;
};

extern "C" u32 fn_94_AF18(Work* work, u32 flag, u32 index) {
    return (work->m_flagWorks[index] & flag) != 0;
}
