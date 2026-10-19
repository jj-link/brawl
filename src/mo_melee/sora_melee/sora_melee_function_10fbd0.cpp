#include <types.h>
#pragma force_active on

class soBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Obj {
    s32 unk0;
    u32 unk4;
    soBase* unk8;
};

extern "C" {
void fn_27_10FBD0(Obj* p, s32 mode) {
    switch (mode) {
    case 0: {
        s32 v = p->unk0;
        if (v != 0) {
            v += 0x40;
        }
        p->unk8 = (soBase*)v;
        break;
    }
    case 1:
        p->unk8 = (soBase*)&p->unk4;
        break;
    }
    p->unk8->f1();
}
}
