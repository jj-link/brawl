#include <types.h>
#pragma force_active on

struct fnTable {
    char pad_00[0x18];
    s32 m_18;
    char pad_1C[0x68 - 0x1C];
    s32 m_68[1];
};

extern "C" s32 fn_27_3A03BC(fnTable* p1, u32 p2, u32 p3) {
    return p1->m_68[p3 - p1->m_18];
}
