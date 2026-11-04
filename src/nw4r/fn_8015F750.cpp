#pragma force_active on

struct IFace {
    virtual void v0();
    virtual int v1();
    virtual int v2();
};

struct Obj {
    char pad0[0x24];
    float f24;
    float f28;
    char pad1[0x1C];
    IFace* p48;
};

extern "C" void fn_8015F750(Obj* self, float farg0, float farg1) {
    float a = farg1 / (float)self->p48->v2();
    float b = farg0 / (float)self->p48->v1();
    self->f28 = a;
    self->f24 = b;
}
