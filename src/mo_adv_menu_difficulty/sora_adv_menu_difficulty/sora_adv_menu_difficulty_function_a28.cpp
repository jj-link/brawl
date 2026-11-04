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
    void setFrameNode(float frame);
};
extern const float lbl_32_rodata_3C;
extern const float lbl_32_rodata_40;
struct Self {
    char p0[0x4c];
    int f4c;
    char p1[0x1b0 - 0x50];
    MuObject* o1b0;
    MuObject* o1b4;
};
extern "C" void fn_32_A28(Self* self) {
    MuObject* a = self->o1b0;
    a->mid->a->s8(lbl_32_rodata_40);
    a->mid->b->s8(lbl_32_rodata_40);
    MuObject* b = self->o1b4;
    b->mid->a->s8(lbl_32_rodata_3C);
    b->setFrameNode((float)self->f4c);
}
