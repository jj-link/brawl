#include <types.h>
#pragma force_active on

struct FlaggedObj {
    u32 m_0;
    u32 m_4;
    u32 m_8;
};

extern "C" {
u32 fn_27_FF1A8(FlaggedObj* obj) {
    u32 val = obj->m_8;
    return (val >> 19) & 1;
}
}
