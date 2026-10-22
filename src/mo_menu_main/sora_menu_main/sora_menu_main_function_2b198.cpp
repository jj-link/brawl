#pragma force_active on
typedef int s32;
typedef unsigned char u8;
extern "C" {
extern void* g_sndSystem;
extern char lbl_2_data_36E8[];
extern const float lbl_2_rodata_EF0;
s32 fn_16_2FD4();
void fn_800B330C(void*, void*, int);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void setFrameMatCol__8MuObjectFf(void*, float);
}

struct Mu {
    char pad[0x10];
    void* u10;
};
struct Obj64 {
    char pad[0x2b4];
    Mu* mu;
};
struct Base3C { char pad[0x3c]; };
struct V25 : Base3C {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22();
    virtual void f64(int a, int b, int c);
};
struct SubV : Base3C {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22();
    virtual void f64();
    char pad1[0x9c - 0x40];
    s32 s9c;
    char pad[0x3e8 - 0xa0];
    s32 s3e8;
    s32 s3ec;
};
struct O654 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10();
    virtual void f34(int a, void* b);
    char p[0xe0];
    int e4;
};
struct S {
    char pad[0x634];
    s32 s634;
    char pad1[0x64c - 0x638];
    Obj64* o64c;
    char pad2[0x654 - 0x650];
    O654* o654;
    V25* o658;
    char pad3[0x664 - 0x65c];
    s32 s664;
    char pad4[0x66c - 0x668];
    u8 s66c;
    char pad5[0x71c - 0x66d];
    SubV* s71c;
    s32 s720;
    u8 s724;
};

extern "C" s32 fn_2_2B198(S* self) {
    s32 r = 0;
    if (self->s724 == 0 && self->s71c->s9c != 1) {
        r = 4;
        self->s724 = 1;
    }
    SubV* p = self->s71c;
    switch (p->s3e8) {
    case 1:
        p->s9c = 7;
        self->s720 = self->s71c->s3ec;
        self->s664 = 1;
        self->s66c &= ~0x40;
        setFrameMatCol__8MuObjectFf(self->o64c->mu, lbl_2_rodata_EF0);
        self->o654->f34(self->o654->e4, self->o64c->mu->u10);
        fn_800B330C(self->o64c->mu, lbl_2_data_36E8 + 0x14, 0);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 5, -1, 0, 0, -1);
        {
            SubV* q = self->s71c;
            q->s3e8 = 0;
            q->s3ec = 0;
        }
        break;
    case 3:
        self->s634 = 1;
        r = 1;
        p->s3e8 = 0;
        p->s3ec = 0;
        break;
    case 4:
        r = 3;
        self->s664 = 3;
        p->f64();
        self->s71c = 0;
        break;
    }
    if (self->s71c && self->s71c->s9c == 2) {
        self->o658->f64((fn_16_2FD4() >> 31) + 0x29, 1, 0);
    }
    return r;
}
