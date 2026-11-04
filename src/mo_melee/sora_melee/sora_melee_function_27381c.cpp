#pragma force_active on
#include <types.h>

extern "C" {
extern float lbl_27_rodata_44C8;
struct Ret { char pad[0x20]; s32 val; };
Ret* fn_8018D6D8(void*, u32);
float getUpdateRate__16gfModelAnimationFv(void*);
void startGimmickSE__9grGimmickFUl(void*, u32);
void stopGimmickSE__9grGimmickFUl(void*, u32);
void startGimmickEffect__9grGimmickFUl(void*, u32);
void stopGimmickEffect__9grGimmickFUl(void*, u32);
}

struct SubObj {
    char pad[0x1C];
    u16 count;
};

class Motion {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void v7(float);
    virtual float v8();
    char pad[0x28];
    SubObj* sub;
};

class gfModelAnimation {
public:
    char pad[0xC];
    Motion* motion;
};

struct GimmickBase {
    char pad[0x3C];
};

class grGimmick : public GimmickBase {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24();
    virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34();
    virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43(); virtual void d44();
    virtual void d45(); virtual void d46(); virtual void d47(); virtual void d48(); virtual void d49();
    virtual void d50(); virtual void d51(); virtual void d52(); virtual void d53(); virtual void d54();
    virtual void d55(); virtual void d56(); virtual void d57(); virtual void d58(); virtual void d59();
    virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63(); virtual void d64();
    virtual void d65(); virtual void d66(); virtual void d67(); virtual void d68(); virtual void d69();
    virtual void d70(); virtual void d71(); virtual void d72(); virtual void d73(); virtual void d74();
    virtual void d75(); virtual void d76(); virtual void d77(); virtual void d78(); virtual void d79();
    virtual void d80(); virtual void d81(); virtual void d82(); virtual void d83(); virtual void d84();
    virtual void d85(); virtual void d86(); virtual void d87(); virtual void d88(); virtual void d89();
    virtual void d90(); virtual void d91(); virtual void d92(); virtual void d93(); virtual void d94();
    virtual void d95(); virtual void d96(); virtual void d97();
    virtual void v100(int);
    virtual void d99(); virtual void d100(); virtual void d101(); virtual void d102(); virtual void d103();
    virtual void d104(); virtual void d105(); virtual void d106(); virtual void d107(); virtual void d108();
    virtual void d109(); virtual void d110(); virtual void d111();
    virtual void v114();

    char pad40[8];
    gfModelAnimation** unk48;
    char pad4C[0x18];
    float unk64;
};

extern "C" void fn_27_27381C(grGimmick* arg0) {
    Motion* m = (*arg0->unk48)->motion;
    if (m != 0 && m->sub->count > 1) {
        float f31 = m->v8();
        gfModelAnimation* anim = *arg0->unk48;
        u16 r28 = anim->motion->sub->count;
        if (getUpdateRate__16gfModelAnimationFv(anim) > lbl_27_rodata_44C8 && f31 < arg0->unk64) {
            u32 i;
            for (i = 0; i < 5; i++) {
                stopGimmickSE__9grGimmickFUl(arg0, i + 3);
            }
            for (s32 j = 0; j < 5; j++) {
                startGimmickSE__9grGimmickFUl(arg0, j + 3);
            }
            for (i = 0; i < 5; i++) {
                stopGimmickEffect__9grGimmickFUl(arg0, i + 3);
            }
            for (s32 k = 0; k < 5; k++) {
                startGimmickEffect__9grGimmickFUl(arg0, k + 3);
            }
            if (fn_8018D6D8(*arg0->unk48, 0)->val == 1) {
                arg0->v114();
            }
        }
        if (f31 + arg0->unk64 >= (f32)r28 && f31 < (f32)r28 &&
            fn_8018D6D8(*arg0->unk48, 0)->val == 1) {
            Motion* m2 = (*arg0->unk48)->motion;
            m2->v7(f31 - (f32)r28);
            arg0->v100(0);
        }
    }
}
