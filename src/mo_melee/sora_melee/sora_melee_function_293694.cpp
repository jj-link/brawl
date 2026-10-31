#pragma force_active on

struct Item {
    int pad;
    int value;
};

class Container {
public:
    virtual void c2();
    virtual void c3();
    virtual Item* get(int i);
    virtual int size();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual unsigned int c16();
};

class Outer {
public:
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual unsigned int o7();

    int pad[3];
    Container m_inner;
};

extern "C" int fn_27_293694(Outer* self) {
    if (self->m_inner.c16() == 1)
        return 0x7FFF;

    if (self->o7() == 1)
        return 0;

    int idx = self->m_inner.size() - 1;
    if (self->m_inner.get(idx)->value < 0x7FFF) {
        idx = self->m_inner.size() - 1;
        return self->m_inner.get(idx)->value + 1;
    }

    int prev;
    int i = self->m_inner.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_inner.get(i)->value == 0)
                return -1;
            return self->m_inner.get(i)->value - 1;
        }

        prev = self->m_inner.get(i - 1)->value;
        if (self->m_inner.get(i)->value - 1 > prev)
            return self->m_inner.get(i)->value - 1;

        i--;
    }

    return -1;
}
