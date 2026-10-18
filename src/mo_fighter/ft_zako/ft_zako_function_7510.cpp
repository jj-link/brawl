#include <types.h>
#pragma force_active on

struct FtZakoWork {
    char pad[0x1c];
    u32* m_flags;
};

extern "C" void fn_126_7510(FtZakoWork* work, u32 mask, u32 index) {
    work->m_flags[index] &= ~mask;
}
