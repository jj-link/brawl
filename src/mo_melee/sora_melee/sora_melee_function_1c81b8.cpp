#include <types.h>
#pragma force_active on

class fnSrcObj {
public:
    u32 m_first;
};

class fnDstObj {
public:
    virtual void vf0();
    virtual u32* vf1(u32 arg);
};

extern "C" {
void fn_27_1C81B8(fnDstObj* self, fnSrcObj* src, u32 arg) {
    u32* dst = self->vf1(arg);
    *dst = src->m_first;
}
}
