#pragma force_active on
typedef int s32;
typedef unsigned char u8;

struct Mu {
    char pad[0x10];
    void* u10;
};
struct Obj64 {
    char pad[0x2b4];
    Mu* mu;
};
struct O654 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12();
    virtual void f60(void* b);
};
struct SubV {
    char pad[0x9c];
    s32 s9c;
    char pad1[0x3e8 - 0xa0];
    s32 s3e8;
    s32 s3ec;
};
struct S {
    char pad[0x64c];
    Obj64* o64c;
    char pad2[0x654 - 0x650];
    O654* o654;
    char pad3[0x664 - 0x658];
    s32 s664;
    char pad4[0x71c - 0x668];
    SubV* s71c;
    s32 s720;
};

extern "C" {
extern char lbl_2_data_36E8[];
s32 fn_2_2B198(S* self);
s32 fn_2_2B3F4(S* self);
s32 fn_16_2B0C(void* arg0, s32 arg1);
void fn_800B330C(void*, void*, int);
}

extern "C" s32 fn_2_2B084(S* self) {
    s32 ret = 0;

    switch (self->s664) {
    case 0:
        ret = fn_2_2B198(self);
        break;
    case 1: {
        s32 r = fn_2_2B3F4(self);
        if (r != 2) {
            if (r == 0) {
                fn_16_2B0C(self->s71c, self->s720);
            }
            self->s71c->s9c = 8;
            fn_800B330C(self->o64c->mu, lbl_2_data_36E8 + 0x3c, 0);
            self->s664 = 2;
        }
        break;
    }
    case 2: {
        SubV* p = self->s71c;
        if (p->s3e8 == 5) {
            p->s3e8 = 0;
            p->s3ec = 0;
            self->o654->f60(self->o64c->mu->u10);
            self->s664 = 0;
        }
        break;
    }
    case 3:
        ret = 3;
        break;
    }
    return ret;
}
