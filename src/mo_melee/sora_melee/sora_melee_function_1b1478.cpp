#include <types.h>
#pragma force_active on

class Primary {
public:
    u32 a, b, c;
    virtual void p0() = 0;
};

class Secondary {
public:
    virtual ~Secondary() { }
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void target() = 0;
};

class Multi : public Primary, public Secondary {
public:
    void call() { target(); }
};

extern "C" void fn_27_1B1478(Multi* self) {
    self->call();
}
