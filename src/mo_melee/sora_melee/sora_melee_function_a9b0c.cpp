#include <types.h>
#pragma force_active on

class SoraElem {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v6(s32 arg);
};

struct fn27A9B0CObj {
    char pad0[0x20];
    s32 m_arg;
    char* m_base;
    char pad28[4];
    s32 m_count;
};

extern "C" void fn_27_A9B0C(fn27A9B0CObj* self, s32 index) {
    u32 flag;

    if (index == -2) {
        flag = 0;
    } else if (index < 0) {
        flag = 1;
    } else {
        flag = self->m_count <= index;
    }

    if (flag != 1) {
        if (index == -2) {
            s32 offset;
            s32 i;
            i = 0;
            offset = 0;
            for (; i < self->m_count; ++i) {
                ((SoraElem*)(self->m_base + offset))->v6(self->m_arg);
                offset += 0x18;
            }
        } else {
            ((SoraElem*)(self->m_base + index * 0x18))->v6(self->m_arg);
        }
    }
}
