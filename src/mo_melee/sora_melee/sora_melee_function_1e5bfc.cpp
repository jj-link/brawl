#include <types.h>
#pragma force_active on

struct Entry {
    int pad;
    int value;
};

class Arr {
public:
    virtual void f0();
    virtual void f1();
    virtual Entry* get(int index);
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
    virtual int f14();
};

class Self {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5();

    int pad[3];
    Arr m_arr;
};

extern "C" int fn_27_1E5BFC(Self* self) {
    if (self->m_arr.f14() == 1U) {
        return 0x7FFF;
    }
    if (self->f5() == 1U) {
        return 0;
    }

    int idx = self->m_arr.size() - 1;
    if (self->m_arr.get(idx)->value < 0x7FFF) {
        idx = self->m_arr.size() - 1;
        return self->m_arr.get(idx)->value + 1;
    }

    int saved;
    int i = self->m_arr.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_arr.get(i)->value == 0) {
                return -1;
            }
            return self->m_arr.get(i)->value - 1;
        }

        saved = self->m_arr.get(i - 1)->value;
        if (self->m_arr.get(i)->value - 1 > saved) {
            return self->m_arr.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
