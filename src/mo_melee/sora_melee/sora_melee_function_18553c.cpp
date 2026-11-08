#include <types.h>
#pragma force_active on

class Vt {
public:
    virtual void p2(); virtual void p3(); virtual void p4(); virtual void p5();
    virtual int v6(u32 a);
    virtual void p7(); virtual void p8();
    virtual void v9(int a);
    virtual void p10(); virtual void p11();
    virtual void v12(float f);
    virtual void p13();
    virtual float v14(u32 a);
    virtual void p15(); virtual void p16(); virtual void p17(); virtual void p18();
    virtual int v19(u32 a);
    virtual void p20();
    virtual void v21();
    virtual void p22(); virtual void p23(); virtual void p24(); virtual void p25(); virtual void p26();
    virtual void v27(int a);
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31(); virtual void p32(); virtual void p33(); virtual void p34();
    virtual void v35(int a);
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39(); virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43(); virtual void p44();
    virtual void v45();
    virtual void p46(); virtual void p47(); virtual void p48(); virtual void p49();
    virtual void v50(int a, int b, int c, int d, float x, float y, float z);
    virtual void p51(); virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55(); virtual void p56(); virtual void p57();
    virtual void p58(); virtual void p59(); virtual void p60(); virtual void p61(); virtual void p62(); virtual void p63(); virtual void p64();
    virtual void p65(); virtual void p66(); virtual void p67(); virtual void p68(); virtual void p69(); virtual void p70(); virtual void p71();
    virtual void p72(); virtual void p73(); virtual void p74(); virtual void p75(); virtual void p76();
    virtual void p77();
};

class Vt2 {
public:
    virtual void p2(); virtual void p3(); virtual void p4(); virtual void p5();
    virtual void v6(u32 a, int b);
    virtual void p7(); virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15(); virtual void p16(); virtual void p17();
    virtual void p18(); virtual void p19(); virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27(); virtual void p28(); virtual void p29();
    virtual void p30(); virtual void p31(); virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39(); virtual void p40(); virtual void p41();
    virtual void p42(); virtual void p43(); virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47();
    virtual void p48(); virtual void p49(); virtual void p50(); virtual void p51(); virtual void p52(); virtual void p53();
    virtual void p54(); virtual void p55(); virtual void p56(); virtual void p57(); virtual void p58(); virtual void p59();
    virtual void p60(); virtual void p61(); virtual void p62(); virtual void p63(); virtual void p64(); virtual void p65();
    virtual void p66(); virtual void p67(); virtual void p68(); virtual void p69(); virtual void p70(); virtual void p71();
    virtual void p72(); virtual void p73(); virtual void p74(); virtual void p75(); virtual void p76();
    virtual void v77(int a, int b, int c, int d, int e);
};

struct Modules {
    char p0[0xC];
    Vt* m0c;
    char p1[0x10];
    Vt* m20;
    char p2[0x30];
    Vt2* m54;
    Vt* m58;
    Vt* m5c;
    char p3[4];
    Vt* m64;
    char p4[0x20];
    Vt* m88;
};

struct Obj8Base {
    char pad[0x3C];
};

class Vt3c : public Obj8Base {
public:
    virtual void q2(); virtual void q3(); virtual void q4(); virtual void q5();
    virtual void q6(); virtual void q7(); virtual void q8(); virtual void q9(); virtual void q10(); virtual void q11();
    virtual void q12(); virtual void q13(); virtual void q14(); virtual void q15(); virtual void q16(); virtual void q17();
    virtual void q18(); virtual void q19(); virtual void q20(); virtual void q21(); virtual void q22(); virtual void q23();
    virtual void q24(); virtual void q25(); virtual void q26(); virtual void q27(); virtual void q28(); virtual void q29();
    virtual void q30(); virtual void q31(); virtual void q32(); virtual void q33(); virtual void q34(); virtual void q35();
    virtual void q36(); virtual void q37(); virtual void q38(); virtual void q39(); virtual void q40(); virtual void q41();
    virtual void q42(); virtual void q43(); virtual void q44();
    virtual void v45();
};

struct Obj {
    char pad0[8];
    Vt3c* o8;
    char pad8[0xCC];
    Modules* mods;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);

extern "C" void fn_27_18553C(void*, Obj* obj) {
    Modules* m = obj->mods;
    Vt* b = m->m0c;
    float f = m->m64->v14(0x21000009);
    b->v12(-f);
    obj->mods->m0c->v21();
    obj->o8->v45();
    obj->mods->m20->v27(0);
    obj->mods->m58->v9(0);
    obj->mods->m88->v35(0);
    float a, c, bb;
    if (obj->mods->m64->v6(0x20000001) == 0x20 || obj->mods->m64->v19(0x22000013) != 0) {
        a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xD56, 0);
        bb = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xD55, 0);
        c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xD54, 0);
    } else {
        if (obj->mods->m64->v6(0x20000001) == 5) {
            float x;
            if (obj->mods->m64->v19(0x22000010) != 0) {
                x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xD40, 0);
            } else {
                x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xD3F, 0);
            }
            a = x;
            bb = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xD3E, 0);
            c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xD3D, 0);
        }
    }
    obj->mods->m5c->v50(0, -1, 0, 0, a, bb, c);
    int r = obj->mods->m64->v6(0x20000002);
    obj->mods->m54->v6(0, r);
    obj->mods->m54->v77(0, 0, 0, 1, 1);
}
