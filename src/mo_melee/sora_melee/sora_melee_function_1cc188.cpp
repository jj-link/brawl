#include <types.h>
#pragma force_active on

struct Item {
    int a;
    int value;
};

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual Item* f2(int i);
    virtual int f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual unsigned f14();
};

class Self {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned f5();

    int pad0;
    int pad1;
    int pad2;
    Sub sub;
};

extern "C" int fn_27_1CC188(Self* self) {
    int prev;
    int var;
    int idx;

    if (self->sub.f14() == 1) {
        return 0x7fff;
    }
    if (self->f5() == 1) {
        return 0;
    }
    idx = self->sub.f3() - 1;
    if (self->sub.f2(idx)->value < 0x7fff) {
        idx = self->sub.f3() - 1;
        return self->sub.f2(idx)->value + 1;
    }
    var = self->sub.f3() - 1;
    while (var >= 0) {
        if (var == 0) {
            if (self->sub.f2(var)->value == 0) {
                return -1;
            }
            return self->sub.f2(var)->value - 1;
        }
        prev = self->sub.f2(var - 1)->value;
        if (self->sub.f2(var)->value - 1 > prev) {
            return self->sub.f2(var)->value - 1;
        }
        var--;
    }
    return -1;
}
