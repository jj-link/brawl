#include <types.h>
#pragma force_active on

struct FnStruct24 {
    u8 pad_00[8];
    s32 m_08;
    s32 m_0c;
    u8 pad_10[4];
    u8 m_14;
};

extern "C" {
bool fn_27_25D334(FnStruct24* p) {
    if (p->m_14 != 0) {
        p->m_08 = 8;
        p->m_0c = 3;
        return true;
    }
    return false;
}
}
