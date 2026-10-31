#include <types.h>
#pragma force_active on

class Element {
public:
    char pad[4];
    int value;
};

class Sub {
public:
    virtual void d0();
    virtual void d1();
    virtual Element* get(int index);
    virtual int size();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual unsigned int check();
};

class Main {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual unsigned int m5();
    char pad[12];
    Sub sub;
};

extern "C" int fn_27_1BAC98(Main* self) {
    if (self->sub.check() == 1) {
        return 0x7FFF;
    }
    if (self->m5() == 1) {
        return 0;
    }

    int idx = self->sub.size() - 1;
    if (self->sub.get(idx)->value < 0x7FFF) {
        idx = self->sub.size() - 1;
        return self->sub.get(idx)->value + 1;
    }

    int prev;
    int i = self->sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->sub.get(i)->value == 0) {
                return -1;
            }
            return self->sub.get(i)->value - 1;
        }
        prev = self->sub.get(i - 1)->value;
        if (self->sub.get(i)->value - 1 > prev) {
            return self->sub.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
