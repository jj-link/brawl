#include <types.h>
#pragma force_active on

extern "C" void fn_27_777D8(void* out, s32 a, s32 b);
extern "C" void fn_27_ABD14(void* a, void* b);

class soSoraObj {
public:
    virtual void vfunc0();
    virtual void* vfunc3(s32 idx);
};

class soSoraOwner {
public:
    u32 m_pad0;
    soSoraObj* m_obj;
    s32 m_defaultIdx;
};

struct soSoraTmp {
    u32 m_w[4];
};

extern "C" void fn_27_76AE0(soSoraOwner* self, s32 a, s32 b) {
    soSoraTmp tmp;
    fn_27_777D8(&tmp, b, b);
    s32 idx;
    if (a <= -1) {
        idx = self->m_defaultIdx;
    } else {
        idx = a;
    }
    void* r = self->m_obj->vfunc3(idx);
    fn_27_ABD14(r, &tmp);
}
