#include <types.h>
#pragma force_active on

class Inner {
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(void *arg);
};

struct Entry {
    char pad[0x10];
    void *value;
};

struct Owner {
    char pad[0x8];
    Inner *inner;
};

extern "C" void fn_800DE5C0(Owner *self) {
    char *p = (char *)self + 0x34;
    for (int i = 13; i < 24; i++) {
        Entry *e = *(Entry **)(p + 0x10);
        if (e != 0) {
            self->inner->f13(e->value);
        }
        p += 4;
    }
}
