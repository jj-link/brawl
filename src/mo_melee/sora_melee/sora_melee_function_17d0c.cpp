#include <types.h>
#pragma force_active on

extern "C" f32 lbl_27_rodata_344;
extern "C" f32 fn_27_20164(void* p);

class Ret {
public:
    u8 pad[0x24];
    u8 m_24;
};

class Inner {
public:
    virtual void v0();
    virtual Ret* vc(int arg);
};

class Outer {
public:
    u8 pad[0x90];
    Inner* m_90;
};

extern "C" {
f32 fn_27_17D0C(Outer* self, int arg) {
    Ret* r = self->m_90->vc(arg);
    f32 ret;
    if (((r->m_24 >> 5) & 1) == 0) {
        ret = fn_27_20164(self->m_90->vc(arg));
    } else {
        ret = lbl_27_rodata_344;
    }
    return ret;
}
}
