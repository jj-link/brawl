#include <types.h>
#pragma force_active on

struct Elem {
    int pad;
    int val;
};

class SubObj {
public:
    virtual void f0();
    virtual void f1();
    virtual Elem* get(int idx);
    virtual int size();
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
    virtual unsigned int f14();
};

class Self {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int f5();
    int pad[3];
    SubObj sub;
};

extern "C" int fn_27_1CB7A4(Self* self) {
    if (self->sub.f14() == 1) {
        return 0x7FFF;
    }
    if (self->f5() == 1) {
        return 0;
    }
    int idx = self->sub.size() - 1;
    if (self->sub.get(idx)->val < 0x7FFF) {
        int idx2 = self->sub.size() - 1;
        return self->sub.get(idx2)->val + 1;
    }
    int i = self->sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->sub.get(i)->val == 0) {
                return -1;
            }
            return self->sub.get(i)->val - 1;
        }
        if (self->sub.get(i)->val - 1 > self->sub.get(i - 1)->val) {
            return self->sub.get(i)->val - 1;
        }
        i--;
    }
    return -1;
}
