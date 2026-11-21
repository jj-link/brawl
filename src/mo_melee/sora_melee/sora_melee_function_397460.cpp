#pragma force_active on

struct VA {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual int s16();
};

struct VB {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21();
    virtual float s22();
};

struct VC {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float s12(unsigned long);
};

struct VDbase { char pad[0x3c]; };
class VD : public VDbase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual int s40();
};

struct Modules {
    char pad0[0xc];
    VB* obj0c;
    char pad1[0x54];
    VC* work;
    char pad2[8];
    VA* obj70;
};

struct Accesser {
    char pad[8];
    VD* status;
    char pad2[0xcc];
    Modules* modules;
};

extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
extern const char lbl_27_rodata_7DA4[];
extern const char lbl_27_rodata_7D98[];
int fn_27_30FACC(void*, unsigned long, int, void*, unsigned long);
float fn_27_192278(void*, unsigned long);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
void fn_27_165458(Accesser*, float, float, float, float, float, float, unsigned long);
void fn_27_164E48(Accesser*, const char*, unsigned long, float, unsigned long);

void fn_27_397460(void* unused, Accesser* a) {
    float f_bbb, f_bb9, f_bba, f_c2e, f_s22, f_prod, f_work;
    VC* w;
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, a->modules->obj70->s16(), a, 1)) {
    case 0x11e:
        f_s22 = a->modules->obj0c->s22();
        f_prod = f_s22 * fn_27_192278(a, 0xfa2);
        w = a->modules->work;
        fn_27_165458(a, w->s12(0x21000004), getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xbbb, 0), getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xbb9, 0), getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xbba, 0), getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xc2e, 0), f_prod, 0x21000004);
        if (a->status->s40() == 5) {
            fn_27_164E48(a, lbl_27_rodata_7DA4, 0x21000004, f_prod, 0x21000005);
        } else {
            fn_27_164E48(a, lbl_27_rodata_7D98, 0x21000004, f_prod, 0x21000005);
        }
        break;
    }
}
}