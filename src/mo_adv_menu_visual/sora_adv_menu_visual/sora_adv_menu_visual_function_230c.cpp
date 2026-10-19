#pragma force_active on
class IFace {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8(float f);
};

struct Mid {
    char p0[0xc];
    IFace* a;
    char p1[0x8];
    IFace* b;
};

class MuObject {
public:
    char pad[0x14];
    Mid* mid;
};

struct Self {
    char pad[0x50];
    MuObject* m;
};

extern const float lbl_29_rodata_28;

extern "C" void fn_29_230C(Self* self) {
    MuObject* const m = self->m;
    m->mid->a->s8(lbl_29_rodata_28);
    m->mid->b->s8(lbl_29_rodata_28);
}
