#pragma force_active on

struct Element {
    int a;
    int b;
};

class Container {
public:
    virtual void v0();
    virtual void v1();
    virtual Element* get(int index);
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
    virtual unsigned check();
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned check();
    unsigned char pad[0x0C];
    Container m_container;
};

extern "C" int fn_27_1C2D2C(Outer* self) {
    if (self->m_container.check() == 1) {
        return 0x7fff;
    }
    if (self->check() == 1) {
        return 0;
    }
    int idx;
    idx = self->m_container.size() - 1;
    if (self->m_container.get(idx)->b < 0x7fff) {
        int idx2;
        idx2 = self->m_container.size() - 1;
        return self->m_container.get(idx2)->b + 1;
    }
    int prev;
    int i;
    i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)->b == 0) {
                return -1;
            }
            return self->m_container.get(i)->b - 1;
        }
        prev = self->m_container.get(i - 1)->b;
        if (self->m_container.get(i)->b - 1 > prev) {
            return self->m_container.get(i)->b - 1;
        }
        i--;
    }
    return -1;
}
