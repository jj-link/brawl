#include <types.h>
#pragma force_active on

struct BitField8 {
    u32 m_0;
    u32 m_4;
    u32 m_8;

    u32 getBit(u32 obj) { return (obj >> 4) & 1; }
};

extern "C" u32 fn_27_B03C4(BitField8* obj)
{
    return (obj->m_8 >> 4) & 1;
}
