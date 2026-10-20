#include <types.h>
#pragma force_active on

class fn27Sec {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class fn27Pad {
public:
    u8 pad[0x10];
};

class fn27Derived : public fn27Pad, public fn27Sec {
public:
    virtual void vf5();
};

extern "C" {
void fn_27_D9D34(fn27Derived& p) {
    fn27Sec& s = p;
    s.vf3();
}
}
