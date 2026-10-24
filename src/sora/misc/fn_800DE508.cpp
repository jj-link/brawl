#include <types.h>
#pragma force_active on

struct Sub {
    char pad[0x10];
    void* m10;
};

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f15(void*);
};

struct Outer {
    s32 pad0;
    s32 m4;
    Obj* m8;
    s32 pad1;
    Sub* m10[4];
};

typedef void (*Fn)(Outer*);

struct Entry {
    Fn fn;
    Fn other;
};

extern const Entry lbl_80408680[];
extern u8 lbl_804086F8[];

extern "C" void fn_800DE508(Outer* self, s32 arg1) {
    for (s32 i = 0; i <= 10; i++) {
        Sub* s = self->m10[lbl_804086F8[i]];
        if (s != 0) {
            self->m8->f15(s->m10);
        }
    }

    Fn f = lbl_80408680[arg1].fn;
    self->m4 = arg1;
    if (f != 0) {
        f(self);
    }
}
