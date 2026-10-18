#include <types.h>
#pragma force_active on

struct Pad8 {
    u32 unk0;
    u32 unk4;
};

class Obj : public Pad8 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(u32 v);
};

extern "C" void fn_27_A1FCC(u8* self, u32 packed) {
    Obj* obj = *(Obj**)(self + ((packed >> 26) & 0x3C) + 0x1c);
    obj->f3(packed & 0xFFFFFF);
}
