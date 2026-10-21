#pragma force_active on
typedef unsigned int u32;

class Sub {
public:
    virtual void v0();
    virtual int getAt(int i);
    virtual void v4();
    virtual int getNum();
};

class Visitor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void visit(int* value);
};

class Owner {
public:
    virtual void v0();
    unsigned char m_pad[0xc];
    Sub m_sub;
};

extern "C" {
void fn_27_F5160(Owner* self, Visitor* vis) {
    int count = self->m_sub.getNum();
    for (int i = 0; i < count; i++) {
        int val = self->m_sub.getAt(i);
        vis->visit(&val);
    }
}
}
