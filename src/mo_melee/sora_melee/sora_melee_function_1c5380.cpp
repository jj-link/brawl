#include <types.h>
#pragma force_active on

class fn_27_1C5380Inner {
public:
    virtual void vf0();
    virtual s32* vf1();
};

struct fn_27_1C5380Outer {
    u8 pad[0x10];
    fn_27_1C5380Inner m_inner;
};

extern "C" s32 fn_27_1C5380(fn_27_1C5380Outer* p) {
    return p->m_inner.vf1()[1];
}
