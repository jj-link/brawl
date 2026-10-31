#include <types.h>
#pragma force_active on

struct Element {
    int pad;
    int value;
};

class Inner {
public:
    virtual int v0();
    virtual int v1();
    virtual Element* get(int index);
    virtual int size();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual unsigned int special();
};

class Outer {
public:
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual unsigned int check();

    char pad[12];
    Inner m_inner;
};

extern "C" int fn_27_1E6FE4(Outer* self) {
    int idx;

    if (self->m_inner.special() == 1)
        return 0x7FFF;

    if (self->check() == 1)
        return 0;

    idx = self->m_inner.size() - 1;
    if (self->m_inner.get(idx)->value < 0x7FFF) {
        idx = self->m_inner.size() - 1;
        return self->m_inner.get(idx)->value + 1;
    }

    idx = self->m_inner.size() - 1;
    for (; idx >= 0; idx--) {
        if (idx == 0) {
            int value = self->m_inner.get(idx)->value;
            if (value == 0)
                return -1;
            return self->m_inner.get(idx)->value - 1;
        }

        if (self->m_inner.get(idx)->value - 1 >
            self->m_inner.get(idx - 1)->value)
            return self->m_inner.get(idx)->value - 1;
    }

    return -1;
}
