#include <mu/mu_object.h>
#include <types.h>
#pragma force_active on

class Anim {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setRate(float rate);
};

class Vt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(void* a, void* b);
    virtual void v12();
    virtual void v13(void* a);
    char pad[0xe0];
    void* fE4;
};

struct Inner {
    char pad0[0xc];
    Anim* a;
    char pad1[4];
    Anim* b;
};

struct MuHolder {
    char pad[0x14];
    Inner* inner;
};

struct Sub {
    char pad[0x10];
    void* p10;
};

class Self {
public:
    char pad0[0x1c];
    s32 f1C;
    char pad1[0xc8 - 0x20];
    MuObject* objC8;
    Sub* pCC[4];
    char pad2[0xf8 - 0xdc];
    Vt* vtF8;
    char pad3[0x354 - 0xfc];
    s32 f354;
    char pad4[0x3a0 - 0x358];
    u8 b3A0;
    char pad5[3];
    s32 f3A4;
};

extern "C" {
extern Vt* lbl_805A02E0;
extern const float lbl_805A23B0;
extern const float lbl_805A23C0;
extern const float lbl_805A23F0;
extern const double lbl_805A23B8;
void fn_800B798C(MuObject* obj, float f);
void fn_800E5318(Self* self, s32 v);
}

extern "C" void fn_800E5174(Self* self, s32 arg1) {
    s32 i;
    Vt* r30;
    self->f354 = arg1;
    Vt* r29 = self->vtF8;
    MuObject* r28 = self->objC8;
    Sub** p;
    lbl_805A02E0->v13(r29);
    if (arg1 != 0) {
        i = 0x29;
        p = (Sub**)((char*)self + 0xa4);
        r30 = self->vtF8;
        do {
            r30->v13(p[10]->p10);
            i++;
            p++;
        } while (i < 0x2d);
        f32 f31;
        switch (arg1) {
        case 1:
            if (self->b3A0 == 0) {
                f31 = lbl_805A23B0;
            } else {
                f31 = lbl_805A23C0;
                r28->setFrameNode((f32)self->f3A4 - f31);
                fn_800B798C(r28, (f32)self->f3A4 - lbl_805A23C0);
                ((MuHolder*)r28)->inner->a->setRate(lbl_805A23B0);
                ((MuHolder*)r28)->inner->b->setRate(lbl_805A23B0);
            }
            break;
        case 2:
            fn_800E5318(self, self->f1C);
            f31 = lbl_805A23F0;
            break;
        }
        self->objC8->setFrameVisible(f31);
        lbl_805A02E0->v11(lbl_805A02E0->fE4, r29);
    }
}
