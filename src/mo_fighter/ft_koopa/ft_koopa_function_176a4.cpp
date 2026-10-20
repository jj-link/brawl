#pragma force_active on
struct ObjA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned int f11(int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual unsigned int f13();
};

struct Holder {
    char pad0[0x3c];
    ObjA* second;
    char pad1[0x54 - 0x40];
    ObjA* first;
};

struct Fighter {
    char pad[0xd8];
    Holder* holder;
};

extern "C" unsigned int fn_102_176A4(void*, Fighter* p) {
    unsigned int r = p->holder->first->f11(0);
    if (r == 1) {
        return p->holder->second->f13();
    }
    return 0;
}
