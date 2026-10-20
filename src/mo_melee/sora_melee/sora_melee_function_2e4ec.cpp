#include <types.h>
#pragma force_active on

struct fn27Sub {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf10(u32 a, u32 b, u32 c, u32 d);
};

struct fn27Obj {
    u8 pad[0x44];
    fn27Sub* m_44;
};

extern "C" u32 fn_27_2E4EC(fn27Obj* self, u32 a, u32 b, u32 c) {
    return self->m_44->vf10(b, a, (u32)self, c);
}
