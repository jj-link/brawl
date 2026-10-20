#include <types.h>
#pragma force_active on

class fn_27_Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

class fn_27_Outer {
public:
    u32 pad[4];
};

extern "C" {
void fn_27_1CD99C(fn_27_Outer* self) {
    reinterpret_cast<fn_27_Inner*>(reinterpret_cast<char*>(self) + 0x10)->v8();
}
}
