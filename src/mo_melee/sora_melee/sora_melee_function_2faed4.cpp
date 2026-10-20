#include <types.h>
#pragma force_active on

struct fn27Tbl {
    u8 pad[0x18];
    s32 m_18;
    u8 pad2[0x38 - 0x1C];
    s32 m_38[1];
};

extern "C" s32 fn_27_2FAED4(fn27Tbl* p1, s32 p2, s32 p3) {
    return p1->m_38[p3 - p1->m_18];
}
