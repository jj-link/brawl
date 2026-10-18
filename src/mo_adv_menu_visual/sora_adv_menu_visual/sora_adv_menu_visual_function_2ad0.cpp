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
    void changeNodeAnimN(const char* name);
    void changeClrAnimN(const char* name);
    char pad[0x14];
    Mid* mid;
};

struct Self {
    char pad[0x50];
    MuObject* m;
    char pad2[0x340 - 0x54];
    int flag;
};

extern char lbl_29_data_1AC[];
extern const float lbl_29_rodata_28;
extern "C" void fn_29_21F0(void* self);

extern "C" void fn_29_2AD0(Self* self) {
    char* const name = lbl_29_data_1AC;
    fn_29_21F0((void*)self);
    MuObject* const m = self->m;
    m->changeNodeAnimN(name);
    m->changeClrAnimN(name);
    m->mid->a->s8(lbl_29_rodata_28);
    m->mid->b->s8(lbl_29_rodata_28);
    self->flag = 0;
}
