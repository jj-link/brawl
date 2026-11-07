#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
};

struct VT {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual float s9();
};
struct VT2 {
    virtual void s0();
    virtual void s1();
    virtual VT2* s2();
};
struct Pad8 { int a, b; };
struct Obj : Pad8 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
    virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35();
    virtual Vec3 f36(int, int);
};
struct Mods {
    char pad[4];
    Obj* m4;
    char pad2[4];
    VT* mC;
    char pad3[8];
    VT2* m18;
};
struct Acc {
    char pad[8];
    char* obj;
    char pad2[0xcc];
    Mods* mods;
};

extern "C" const float lbl_105_rodata_10;
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned, unsigned);
extern "C" void fn_105_17E50(void*, void*, void*, Vec3*, float);

extern "C" int fn_105_BF18(void* arg0, Acc* acc) {
    Vec3 v = acc->mods->m4->f36(0x27, 0);
    float sf = (float)((acc->mods->mC->s9() < lbl_105_rodata_10) ? -1 : 1);
    float t = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfa4, 0);
    v.x += t * sf;
    v.y += getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfa5, 0);
    v.z = lbl_105_rodata_10;
    Mods* m = acc->mods;
    VT2* r31 = m->m18;
    void* o = *(void**)(acc->obj + 0x28);
    float f = m->mC->s9();
    VT2* a = r31->s2();
    void* b = a->s2();
    fn_105_17E50(arg0, o, b, &v, f);
    return 0;
}
