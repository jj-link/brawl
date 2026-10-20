#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual s32 vf4() = 0;
    virtual void vf5(s32 v) = 0;
};

class fnOuter {
public:
    u8 pad[0x28];
    fnInner* m_inner;
};

extern "C" {
void fn_27_B56E0(fnOuter* self, s32 v) {
    if (v != self->m_inner->vf4()) {
        self->m_inner->vf5(v);
    }
}
}
