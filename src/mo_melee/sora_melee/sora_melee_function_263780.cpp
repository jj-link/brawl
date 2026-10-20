#pragma force_active on
class soInnerA {
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
};

struct soPad8 {
    int a;
    int b;
};

class soInnerB : public soPad8 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(void* p);
};

struct soHolder {
    char pad0[0x20];
    soInnerA* m_a;
    char pad1[0x38 - 0x24];
    soInnerB* m_b;
};

class soOwner {
public:
    char pad[0x180];
    soHolder* m_holder;
};

extern "C" {
    void fn_27_263780(soOwner* self, void* arg) {
        self->m_holder->m_a->v8();
        self->m_holder->m_b->v6(arg);
    }
}
