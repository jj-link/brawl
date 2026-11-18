#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getParamFloat__8BaseItemFUl(void*, unsigned long);
void fn_27_2B995C(void*, float*, float*, void*);
extern const char lbl_27_data_71BE0[];
extern const char lbl_27_data_CDC0[];
extern const float lbl_27_rodata_46C8[];
}

struct Pair {
    float x;
    float y;
};

class ObjA {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int call14();
};

class ObjC {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual Pair call3C(short*, void*);
    virtual void v40(); virtual void v44(); virtual void v48();
    virtual void call4C(float*, short*);
};

class ObjM {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24();
    virtual void v28();
    virtual float call2C();
    virtual void call30(float);
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void call54();
};

struct Mods {
    char p0[0xC];
    ObjM* mC;
    char p10[4];
    ObjA* m14;
    char p18[0x64];
    void* m7C;
};

struct Outer {
    char pad[0xD8];
    Mods* mD8;
};

struct ItemPad {
    char pad[0x3C];
};

class ItemBase : public ItemPad {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0();
    virtual void callB4();
    char pad2[0x60 - 0x40];
    Outer* m60;
    char pad3[0x8C0 - 0x64];
    int m8C0;
};

static Pair wrapCall3C(ObjC* c, short* s, void* md) {
    return c->call3C(s, md);
}

extern "C" int fn_27_29D9D8(void*, ItemBase* self) {
    const float* c = lbl_27_rodata_46C8;
    if (((ObjA*)self->m60->mD8->m14)->call14() != 0) {
        return 1;
    }
    ObjM* m;
    ObjC* cc = (ObjC*)__dynamic_cast(self->m60->mD8->m7C, 0, lbl_27_data_71BE0, lbl_27_data_CDC0, 1);
    Mods* md = self->m60->mD8;
    m = md->mC;
    struct { short value; short padding; } s;
    s.value = 1;
    Pair r = wrapCall3C(cc, &s.value, md);
    float ax = (float)(double)nw4r::math::FAbs(r.x);
    float v[3];
    v[0] = c[5];
    v[1] = c[5];
    v[2] = c[5];
    if (ax > c[34]) {
        v[1] = c[36] * r.x;
    }
    Outer* outer = self->m60;
    float w[3];
    w[0] = c[5];
    w[1] = c[5];
    w[2] = c[5];
    fn_27_2B995C(cc, v, w, outer);
    float p = c[5];
    switch (self->m8C0) {
    case 0x1C:
        p = getParamFloat__8BaseItemFUl(self, 0x1519);
        break;
    case 0x51:
        p = getParamFloat__8BaseItemFUl(self, 0x1F73);
        break;
    case 0x52:
        p = getParamFloat__8BaseItemFUl(self, 0x1FA5);
        break;
    }
    if (ax < p) {
        short s2 = 1;
        float u[3];
        u[0] = c[37];
        u[1] = c[37];
        u[2] = c[37];
        ((ObjC*)self->m60->mD8->m7C)->call4C(u, &s2);
    }
    if (r.x > c[5] && c[0] != m->call2C()) {
        m->call30(c[0]);
        m->call54();
        self->callB4();
    } else if (r.x < c[5] && c[4] != m->call2C()) {
        m->call30(c[4]);
        m->call54();
        self->callB4();
    }
    return 1;
}
