#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void f0();
    virtual s32 f1(s32 idx);
};

class fnOuter {
public:
    s32 m_0;
    fnInner* m_inner;
    s32 m_default;
};

extern "C" s32 fn_27_AB428(s32, s32);

extern "C" s32 fn_27_76B50(fnOuter* self, s32 a, s32 index) {
    s32 idx;
    if (index <= -1) {
        idx = self->m_default;
    } else {
        idx = index;
    }
    s32 r = self->m_inner->f1(idx);
    return fn_27_AB428(r, a);
}
