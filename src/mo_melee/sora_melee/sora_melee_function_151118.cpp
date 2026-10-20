#include <types.h>
#pragma force_active on

struct fnSub27 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct fnOuter27 {
    u8 pad[0x30];
    fnSub27 sub;
};

extern "C" {
void fn_27_151118(fnOuter27* p) {
    p->sub.f2();
}
}
