#include <types.h>
#pragma force_active on

class soObj {
public:
    virtual void vf0();
    virtual u8* vf1(s32 idx);
};

struct Holder {
    u32 pad;
    soObj* obj;
    s32 defIdx;
};

extern "C" void fn_27_76C90(Holder* h, s32 idx) {
    Holder* self = h;
    soObj* obj = self->obj;
    idx = (idx <= -1) ? self->defIdx : idx;
    u8* p = obj->vf1(idx);
    *p |= 0x80;
}
