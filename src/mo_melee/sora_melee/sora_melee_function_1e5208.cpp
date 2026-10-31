#pragma force_active on

struct Item {
    int pad;
    int value;
};

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual Item* get(unsigned int index);
    virtual unsigned int count();
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
    virtual unsigned int check();
};

class Owner {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual unsigned int o5();
    char pad[0xC];
    Sub m_sub;
};

extern "C" int fn_27_1E5208(Owner* self) {
    if (self->m_sub.check() == 1) {
        return 0x7FFF;
    }
    if (self->o5() == 1) {
        return 0;
    }
    int idx = self->m_sub.count() - 1;
    if (self->m_sub.get(idx)->value < 0x7FFF) {
        idx = self->m_sub.count() - 1;
        return self->m_sub.get(idx)->value + 1;
    }
    int i = self->m_sub.count() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_sub.get(i)->value == 0) {
                return -1;
            }
            return self->m_sub.get(i)->value - 1;
        }
        if (self->m_sub.get(i)->value - 1 > self->m_sub.get(i - 1)->value) {
            return self->m_sub.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
