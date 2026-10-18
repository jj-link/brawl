#include <types.h>
#pragma force_active on

struct Pad27 {
    u32 a;
    u32 b;
};

class Obj27 : public Pad27 {
public:
    virtual void f0(u32 arg);
    virtual void f1(u32 arg);
    virtual void f2(u32 arg);
    virtual void f3(u32 arg);
    virtual void f4(u32 arg);
    virtual void f5(u32 arg);
    virtual void f6(u32 arg);
    virtual void f7(u32 arg);
    virtual void f8(u32 arg);
    virtual void f9(u32 arg);
    virtual void f10(u32 arg);
    virtual void f11(u32 arg);
    virtual void f12(u32 arg);
    virtual void call(u32 arg);
};

extern "C" void fn_27_A21C0(char* self, u32 arg) {
    u32 idx = (arg >> 26) & 0x3C;
    Obj27* obj = *(Obj27**)(self + idx + 0x1c);
    obj->call(arg & 0xFFFFFF);
}
