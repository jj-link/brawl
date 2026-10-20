#pragma force_active on
typedef unsigned int u32;

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Owner {
    u32 pad[4];
    Sub s;
};

extern "C" void fn_27_319430(Owner* p) {
    p->s.v1();
}
