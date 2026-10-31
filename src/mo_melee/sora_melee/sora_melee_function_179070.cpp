#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(u32 a, u32 b);
    virtual void f10();
    virtual void f11();
};

extern "C" {
void fn_27_179070(void* unused, u8* obj, s32 kind) {
    if (kind == 0x3b) {
        return;
    }
    if (kind < 0x3b) {
        if (kind == 0) {
            return;
        }
    }
    fn27Inner* inner = *(fn27Inner**)((u8*)*(void**)(obj + 0xd8) + 0x3c);
    inner->f9(0, 0);
}
}
