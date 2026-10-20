#include <types.h>
#pragma force_active on

struct BitField32 {
    u32 m_0;
    u32 m_4;
    u32 m_8;

    u32 getBit(u32 obj) { return (obj >> 19) & 1; }
};

extern "C" u32 fn_27_198B50(BitField32* obj)
{
    return (obj->m_8 >> 19) & 1;
}
