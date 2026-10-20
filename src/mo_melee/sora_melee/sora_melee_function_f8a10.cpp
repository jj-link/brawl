#include <types.h>
#pragma force_active on

class Prim {
public:
    virtual void p();
    u32 a;
    u32 b;
    u32 c;
};

class Sec {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};

class Der : public Prim, public Sec {
public:
    virtual void d();
};

extern "C" {
void fn_27_F8A10(Der& self) {
    Sec& s = self;
    s.b();
}
}
