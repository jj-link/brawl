#pragma force_active on

class Element {
public:
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
    virtual unsigned int v14();
};

class Main {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual unsigned int m5();

    char pad[0xC];
    Container m_container;
};

extern "C" int fn_27_1CA3DC(Main* self) {
    if (self->m_container.v14() == 1U) {
        return 0x7FFF;
    }

    if (self->m5() == 1U) {
        return 0;
    }

    int index = self->m_container.size() - 1;
    if (self->m_container.get(index)->b < 0x7FFF) {
        index = self->m_container.size() - 1;
        return self->m_container.get(index)->b + 1;
    }

    int i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)->b == 0) {
                return -1;
            }
            return self->m_container.get(i)->b - 1;
        }

        if (self->m_container.get(i)->b - 1 >
            self->m_container.get(i - 1)->b) {
            return self->m_container.get(i)->b - 1;
        }

        --i;
    }

    return -1;
}
