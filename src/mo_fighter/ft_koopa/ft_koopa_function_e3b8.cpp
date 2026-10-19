#pragma force_active on
struct ModVt {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual unsigned int s11(int);
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual unsigned int s15();
};

struct Sub {
    char pad0[0x3c];
    ModVt* b;
    char pad1[0x54 - 0x40];
    ModVt* a;
};

struct Obj {
    char pad[0xd8];
    Sub* sub;
};

extern "C" unsigned int fn_102_E3B8(void*, Obj* obj) {
    if (obj->sub->a->s11(0) == 1) {
        return obj->sub->b->s15();
    }
    return 0;
}
