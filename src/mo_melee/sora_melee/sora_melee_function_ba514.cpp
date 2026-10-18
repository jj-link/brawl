#pragma force_active on
class Vec3f;

class BaseItem {
public:
    void warp(Vec3f* v);
};

class Sub {
public:
    virtual void v0();
    virtual Sub* v3(Vec3f* v);
    BaseItem* m_4;
};

class Owner {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual bool test(Vec3f* v);
    char pad[0x34];
    Sub* m_38;
};

extern "C" void fn_27_BA514(Owner* self, Vec3f* a, Vec3f* b) {
    if (self->test(b)) {
        self->m_38->v3(b)->m_4->warp(a);
    }
}
