#pragma force_active on

struct Elem {
    int pad;
    int value;
};

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual Elem* get(int index);
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
    virtual unsigned int full();
};

class Owner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int check();
    char pad[12];
    Obj m_obj;
};

extern "C" int fn_27_C4F60(Owner* self) {
    if (self->m_obj.full() == 1)
        return 0x7FFF;

    if (self->check() == 1)
        return 0;

    int idx = self->m_obj.size() - 1;
    if (self->m_obj.get(idx)->value < 0x7FFF) {
        idx = self->m_obj.size() - 1;
        return self->m_obj.get(idx)->value + 1;
    }

    int prev;
    int i = self->m_obj.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_obj.get(i)->value == 0)
                return -1;
            return self->m_obj.get(i)->value - 1;
        }
        prev = self->m_obj.get(i - 1)->value;
        if (self->m_obj.get(i)->value - 1 > prev)
            return self->m_obj.get(i)->value - 1;
        i--;
    }
    return -1;
}
