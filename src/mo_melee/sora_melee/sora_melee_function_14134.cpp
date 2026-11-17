#include <types.h>
#pragma force_active on

namespace nw4r { namespace g3d { struct AnmObjChrRes; } }

class soAnimChr {
public:
    nw4r::g3d::AnmObjChrRes* m_anmChrRes;
    float m_animFrame;
    float m_startFrame;
    float m_saveFrame;
    float m_rate;
    float m_frameAhead;
    u8 m_loopFlag : 1;
    u8 m_reverseFlag : 1;
    void updateFrame(float frame);
};

extern "C" void fn_27_20084(void*, float);
extern "C" void fn_27_207BC(void*, float);
extern "C" const f32 lbl_27_rodata_340;
extern "C" const f32 lbl_27_rodata_344;

struct Base8 { char pad[8]; };

struct Pair {
    soAnimChr a;
    int kind1;
    soAnimChr b;
    int kind2;
};

struct PairArray {
    virtual void v0();
    virtual Pair* get(int);
    virtual void v2();
    virtual int count();
};

struct Partial {
    char pad[0x28];
    int m28;
};

struct PartialArray {
    virtual void v0();
    virtual Partial* get(int);
    virtual void v2();
    virtual int count();
};

struct RateObj : Base8 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual float getRate(void* accesser);
};

struct NotifyObj : Base8 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void notify();
};

struct Modules {
    char pad[4];
    NotifyObj* notifyObj;
    char pad2[0xB8 - 8];
    RateObj* rateObj;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void setFrame(float frame);
    char pad[0x38];
    soAnimChr m3c;
    char pad2[0x5C - 0x58];
    float m5c;
    char pad3[0x68 - 0x60];
    float m68;
    soAnimChr m6c;
    int m88;
    PairArray* m8c;
    PartialArray* m90;
    int m94;
    char pad4[0x164 - 0x98];
    u8 m164;
    u8 m165;
    char pad5[0x168 - 0x166];
    Accesser* m168;
};

extern "C" void fn_27_14134(Self* self, float arg) {
    float blend;
    Pair* p;
    float rate = arg * self->m168->modules->rateObj->getRate(self->m168);
    self->m3c.updateFrame(rate);
    if (self->m94 != 0) {
        int n = self->m8c->count();
        for (int i = 0; i < n; i++) {
            p = self->m8c->get(i);
            if (p->kind1 != -1) {
                p->a.updateFrame(rate);
            }
            if (p->kind2 != -1) {
                p->b.updateFrame(rate);
            }
        }
        if (self->m88 != -1) {
            blend = self->m5c;
            self->m6c.updateFrame(rate);
            if ((u32)((self->m165 >> 6) & 1) == 1) {
                blend += self->m68;
            } else {
                blend += self->m68 * rate;
            }
            if (blend > lbl_27_rodata_340) {
                blend = lbl_27_rodata_340;
            } else if (blend < lbl_27_rodata_344) {
                blend = lbl_27_rodata_344;
            }
            self->setFrame(blend);
        }
    }
    int pn = self->m90->count();
    for (int i = 0; i < pn; i++) {
        Partial* pp = self->m90->get(i);
        if (pp->m28 != -1) {
            fn_27_207BC(pp, rate);
        }
    }
    if (self->m3c.m_anmChrRes != NULL) {
        self->m168->modules->notifyObj->notify();
    }
    fn_27_20084((char*)self + 0xC8, self->m3c.m_animFrame);
    self->m164 &= ~0x08;
    self->m165 &= ~0x3C;
}
