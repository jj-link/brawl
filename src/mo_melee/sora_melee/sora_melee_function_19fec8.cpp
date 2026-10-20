#include <types.h>
#pragma force_active on

struct Flags {
    u32 m_0;
    u32 m_4;
    u32 m_8 : 4;
};

extern "C" void fn_27_19FEC8(Flags *flags, int val) {
    flags->m_8 = val;
}
