#include <types.h>
#pragma force_active on

struct soRet {
    s32 pad;
    s32 value;
};

struct soSub {
    virtual void vf0();
    virtual soRet* getRet();
};

struct soOuter {
    u8 pad[0x10];
    soSub m_sub;
};

extern "C" s32 fn_27_1C98BC(soOuter* self) {
    return self->m_sub.getRet()->value;
}
