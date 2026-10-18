#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void* vf0();
    virtual void* vf1(s32 index);
};

struct fn27Holder {
    u32 m_pad;
    fn27Obj* m_obj;
    s32 m_default;
};

extern "C" void fn_27_777D8(void* out, s32 a, s32 b);
extern "C" void fn_27_ABBDC(void* obj, s32 a, void* out);

extern "C" void fn_27_76A60(fn27Holder* self, s32 index, s32 p5, s32 p6) {
    u32 tmp[4];
    fn_27_777D8(tmp, p6, p5);
    s32 idx;
    fn27Obj* obj = self->m_obj;
    if (index <= -1) {
        idx = self->m_default;
    } else {
        idx = index;
    }
    void* ret = obj->vf1(idx);
    fn_27_ABBDC(ret, p5, tmp);
}
