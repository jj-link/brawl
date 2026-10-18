#include <types.h>

#pragma force_active on

// ft_gamewatch: clear the flag, float and int work entries of a general work
// object by writing zero into the packed work slots (offsets 0x10, 0xc, 0x8).
struct RawWork {
    u32 m_reserved[2];
    u32 m_flagWork;
    u32 m_floatWork;
    u32 m_intWork;
};

extern "C" void fn_107_168B4(RawWork* work, u32 value) {
    work->m_intWork = value;
    work->m_floatWork = value;
    work->m_flagWork = value;
}
