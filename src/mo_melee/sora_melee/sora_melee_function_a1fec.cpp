#include <types.h>
#pragma force_active on

struct Base0 {
    u32 unk0;
    u32 unk4;
};

class Ent : public Base0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(u32 a, u32 b);
    virtual void f5();
    virtual void f6();
};

extern "C" void fn_27_A1FEC(void* self, u32 a, u32 b) {
    Ent* e = *(Ent**)((u8*)self + 0x1c + ((b >> 26) & 0x3C));
    e->f4(a, b & 0xFFFFFF);
}
