#pragma force_active on

struct Elem {
    int unk0;
    int val;
};

class Container {
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
    virtual unsigned firstCheck();
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned secondCheck();
    char pad[12];
    Container m_container;
};

extern "C" int fn_27_390038(Owner* self) {
    if (self->m_container.firstCheck() == 1)
        return 0x7FFF;

    if (self->secondCheck() == 1)
        return 0;

    {
        int idx = self->m_container.size() - 1;
        if (self->m_container.get(idx)->val < 0x7FFF) {
            int idx2 = self->m_container.size() - 1;
            return self->m_container.get(idx2)->val + 1;
        }
    }

    for (int i = self->m_container.size() - 1; i >= 0; i--) {
        if (i == 0) {
            if (self->m_container.get(i)->val == 0)
                return -1;
            return self->m_container.get(i)->val - 1;
        }
        if (self->m_container.get(i)->val - 1 > self->m_container.get(i - 1)->val)
            return self->m_container.get(i)->val - 1;
    }
    return -1;
}
