#include <types.h>
#pragma force_active on

extern "C" {

s32 randi__Fl(s32);

class PeachAction {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int method6(int param);
    virtual void method7(int param1, int param2);
};

struct Inner {
    u8 pad[0x64];
    PeachAction* action;
};

struct Outer {
    u8 pad[0xD8];
    Inner* inner;
};

void fn_103_D2C4(s32 unused, Outer* outer) {
    Inner* inner = outer->inner;
    PeachAction* action = inner->action;
    int forbidden = action->method6(0x10000040);
    int value;
    do {
        value = randi__Fl(3);
    } while (value == forbidden);
    action->method7(value, 0x10000040);
}

}
