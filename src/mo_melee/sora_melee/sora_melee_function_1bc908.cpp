#include <types.h>
#pragma force_active on

struct soInnerData {
    s32 a;
    s32 b;
};

class soInner {
public:
    virtual void vf0();
    virtual soInnerData* getData();
};

struct soOuter {
    s32 pad[4];
    soInner m_inner;
};

extern "C" s32 fn_27_1BC908(soOuter* self) {
    return self->m_inner.getData()->b;
}
