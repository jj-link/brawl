#pragma force_active on

class Elem {
public:
    unsigned char pad[4];
    int field4;
};

class Container {
public:
    virtual int d0();
    virtual int d1();
    virtual Elem* get(int index);
    virtual int size();
    virtual int d4();
    virtual int d5();
    virtual int d6();
    virtual int d7();
    virtual int d8();
    virtual int d9();
    virtual int d10();
    virtual int d11();
    virtual int d12();
    virtual int d13();
    virtual unsigned m14();
};

class Main {
public:
    virtual int d0();
    virtual int d1();
    virtual int d2();
    virtual int d3();
    virtual int d4();
    virtual unsigned v5();

    int unk04;
    int unk08;
    int unk0C;
    Container m_container;
};

extern "C" int fn_27_1BFBB8(Main* self) {
    if (self->m_container.m14() == 1) {
        return 0x7FFF;
    }
    if (self->v5() == 1) {
        return 0;
    }

    int idx = self->m_container.size() - 1;
    if (self->m_container.get(idx)->field4 < 0x7FFF) {
        idx = self->m_container.size() - 1;
        return self->m_container.get(idx)->field4 + 1;
    }

    int prev;
    int i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)->field4 == 0) {
                return -1;
            }
            return self->m_container.get(i)->field4 - 1;
        }
        prev = self->m_container.get(i - 1)->field4;
        if (self->m_container.get(i)->field4 - 1 > prev) {
            return self->m_container.get(i)->field4 - 1;
        }
        i--;
    }
    return -1;
}
