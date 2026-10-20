#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void vfunc0();
    virtual s32* getPtr(u32 index);
    virtual void vfunc2();
    virtual u32 getCount();
};

class fnOuter {
public:
    u8 pad[0x6d8];
    fnInner m_inner;
};

extern "C" s32 fn_27_2A898C(fnOuter* self, u32 index) {
    if (index >= self->m_inner.getCount()) {
        return 0;
    }
    return *self->m_inner.getPtr(index);
}
