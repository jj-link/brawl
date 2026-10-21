#pragma force_active on
struct soModuleAccesser;

struct Target {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual int v6(int) = 0;
    virtual void v7(int, int) = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual int v18() = 0;
};

struct Mid {
    unsigned char pad[0x64];
    Target* target;
};

struct Mid70 {
    unsigned char pad[0x70];
    Target* target;
};

struct X60 {
    unsigned char pad[0xd8];
    Mid* mid;
};

struct soValueAccesser {
    unsigned char pad[0xd8];
    Mid70* z;
    void getConstantInt(soModuleAccesser*, unsigned long, unsigned long);
};

struct Fighter {
    unsigned char pad[0x60];
    X60* x60;
};

extern "C" void fn_27_131CD0(void*, int, int, soValueAccesser*);

extern "C" void fn_95_A3C4(Fighter* self, int arg1, int arg2, soValueAccesser* accesser) {
    int r30 = self->x60->mid->target->v6(0x10000001);
    fn_27_131CD0(self, arg1, arg2, accesser);
    if (accesser->z->target->v18() == 0xC) {
        unsigned long u;
        accesser->getConstantInt((soModuleAccesser*)0x59db, 0, u);
        self->x60->mid->target->v7(r30, 0x10000001);
    }
}
