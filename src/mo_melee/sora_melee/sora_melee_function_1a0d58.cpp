#include <types.h>
#pragma force_active on

namespace {
    struct BitHolder {
        u32 m_00;
        u32 m_04;
        u32 m_08;
    };
}

extern "C" {

bool fn_27_1A0D58(const BitHolder* holder)
{
    return (holder->m_08 >> 22) & 1;
}

}

