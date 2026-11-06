#include <types.h>
#pragma force_active on

struct VtA {
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
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual int f17(int);
};

struct VtB {
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

struct Holder {
    char pad0[0x64];
    VtA* a;
    char pad1[0xA8 - 0x68];
    VtB* b;
};

struct Outer {
    char pad[0xD8];
    Holder* holder;
};

extern "C" void fn_27_396D2C(void* self, Outer* outer) {
    if (outer->holder->a->f17(0x2200001A) == 0) {
        for (int i = 3; i < 7; i++) {
            if (outer->holder->b->f14(i)) {
                outer->holder->b->f27(i);
            }
        }
    }
}
