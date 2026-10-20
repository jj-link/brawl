#include <types.h>
#pragma force_active on

struct soInnerRet {
    s32 m_pad;
    s32 m_val;
};

class soInnerObj {
public:
    virtual void slot0();
    virtual soInnerRet* slot1();
};

class soOuterObj {
public:
    u32 m_pad[4];
    soInnerObj m_inner;
};

extern "C" s32 fn_27_264580(soOuterObj* p) {
    return p->m_inner.slot1()->m_val;
}
