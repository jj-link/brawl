#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void vf0();
    virtual fn27Obj* vf1(u32 x);
    virtual void vf2();
    virtual void vf3();
};

extern "C" {
void fn_27_F6C74(fn27Obj* self, u32* src, u32 x) {
    fn27Obj* r = self->vf1(x);
    *(u32*)r = *src;
}
}
