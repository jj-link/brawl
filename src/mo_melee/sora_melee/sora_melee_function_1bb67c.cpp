#include <types.h>
#pragma force_active on

struct Elem {
    int a;
    int b;
};

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual Elem* get(int idx);
    virtual int size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual unsigned int check();
};

class Main {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int check();
    int pad[3];
    Sub m_sub;
};

extern "C" int fn_27_1BB67C(Main* self) {
    if (self->m_sub.check() == 1) {
        return 0x7FFF;
    }
    if (self->check() == 1) {
        return 0;
    }

    int idx = self->m_sub.size() - 1;
    if (self->m_sub.get(idx)->b < 0x7FFF) {
        idx = self->m_sub.size() - 1;
        return self->m_sub.get(idx)->b + 1;
    }

    int prev;
    int i = self->m_sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_sub.get(i)->b == 0) {
                return -1;
            }
            return self->m_sub.get(i)->b - 1;
        }
        prev = self->m_sub.get(i - 1)->b;
        if (self->m_sub.get(i)->b - 1 > prev) {
            return self->m_sub.get(i)->b - 1;
        }
        i--;
    }
    return -1;
}
