#include <types.h>
#pragma force_active on

struct fn_27_2D7C28_arg {
    s32 unk0;
    float unk4;
};

class fn_27_2D7C28_base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(u32 a, u32 b, float c, s32 d, s32 e);
};

extern "C" {
void fn_27_2D7C28(fn_27_2D7C28_base* self, u32 a, u32 b, fn_27_2D7C28_arg* p) {
    self->vf2(a, b, p->unk4, 1, 0);
}
}
