#include <types.h>
#pragma force_active on

class IFoo {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};

struct Outer {
    u8 pad[0x10];
    IFoo sub;
};

extern "C" {
void fn_27_1B1548(Outer* p) {
    p->sub.d();
}
}
