#include <types.h>
#pragma force_active on

struct Vt {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual int f14(int);
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void f27(int);
};

struct Owner {
    char pad[0xA8];
    Vt* vt;
};

struct Outer {
    char pad[0xD8];
    Owner* owner;
};

extern "C" void fn_27_35877C(void* self, int id, void* a, void* b, Outer* outer) {
    if (id != 0x112 && id != 0x117 && id != 0x11C && id != 0x11D && id != 0x11E && id != 0x11F && id != 0x120) {
        for (int i = 3; i < 7; i++) {
            if (outer->owner->vt->f14(i)) {
                outer->owner->vt->f27(i);
            }
        }
    }
}
