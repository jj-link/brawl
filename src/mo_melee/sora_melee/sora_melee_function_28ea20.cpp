#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct Pre8 {
    int a;
    int b;
};

extern "C" const float lbl_27_rodata_4610;

class Big {
public:
    virtual void f0(int a);
    virtual void d1();
    virtual void* f2(int a);
    virtual void d3();
    virtual void f4();
    virtual void f5(int a);
    virtual void f6(int a);
    virtual void d7();
    virtual void d8();
    virtual int f9(int a);
    virtual void f10(int a);
    virtual void d11();
    virtual float f12(int a);
    virtual void f13(int a, float b);
    virtual void d14();
    virtual void d15();
    virtual int f16();
    virtual void d17();
    virtual void d18();
    virtual void f19(int a, int b);
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void f33();
};

class HObj {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5();
    virtual void f6(int a, int b);
};

class Poly8 : public Pre8 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18();
    virtual void f19(int a, int b);
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24();
    virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34();
    virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43(); virtual void d44();
    virtual void d45();
    virtual int f46(void* a);
    virtual void d47(); virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51();
    virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55(); virtual void d56();
    virtual void d57(); virtual void d58(); virtual void d59(); virtual void d60(); virtual void d61();
    virtual void d62(); virtual void d63(); virtual void d64(); virtual void d65(); virtual void d66();
    virtual void d67(); virtual void d68(); virtual void d69(); virtual void d70(); virtual void d71();
    virtual void d72(); virtual void d73(); virtual void d74(); virtual void d75(); virtual void d76();
    virtual void d77(); virtual void d78(); virtual void d79(); virtual void d80(); virtual void d81();
    virtual void d82(); virtual void d83(); virtual void d84(); virtual void d85(); virtual void d86();
    virtual void d87(); virtual void d88(); virtual void d89(); virtual void d90(); virtual void d91();
    virtual void d92(); virtual void d93(); virtual void d94(); virtual void d95(); virtual void d96();
    virtual void d97(); virtual void d98(); virtual void d99(); virtual void d100(); virtual void d101();
    virtual void d102(); virtual void d103(); virtual void d104(); virtual void d105(); virtual void d106();
    virtual void d107(); virtual void d108(); virtual void d109(); virtual void d110(); virtual void d111();
    virtual void d112(); virtual void d113(); virtual void d114(); virtual void d115(); virtual void d116();
    virtual void d117(); virtual void d118(); virtual void d119(); virtual void d120(); virtual void d121();
    virtual void d122(); virtual void d123(); virtual void d124(); virtual void d125(); virtual void d126();
    virtual void f127(int a);
};

class VecObj {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual Vec3f f4();
};

extern "C" int fn_27_28EA20(char* self, int arg1, float farg0) {
    void* mod = *(void**)(self + 0x1a4);
    void* obj = *(void**)((char*)mod + 0x70);
    int r = ((Big*)obj)->f16();
    if (r == 2) {
        r = 1;
    }
    else {
        r = ((Big*)(self + 0x27a8))->f9(3);
    }

    int ok;
    if (r != 0 || ((Poly8*)*(void**)(self + 0x8d0))->f46(self) == 0) {
        ok = 0;
    } else {
        unsigned int* flags = (unsigned int*)((Big*)(self + 0x297c))->f2(8);
        ok = (*flags & 0x01000000) ? 0 : 1;
    }
    if (!ok) {
        return 0;
    }

    void* o2 = self + 0x2aac;
    float f31 = ((Big*)o2)->f12(0x1100000D);
    if (f31 < lbl_27_rodata_4610) {
        const Vec3f& v = ((VecObj*)(self + 0xdb4))->f4();
        *(float*)(self + 0x3d50) = v.x;
        *(float*)(self + 0x3d54) = v.y;
        *(float*)(self + 0x3d58) = v.z;
        void* q = *(void**)((char*)*(void**)((char*)*(void**)(self + 0x60) + 0xd8) + 0x44);
        ((Big*)q)->f0(1);
        ((Big*)(self + 0x3a68))->f10(0);
        ((Poly8*)(self + 0xe7c))->f19(0, 0);
        ((Poly8*)(self + 0xe7c))->f127(0);
        ((HObj*)(self + 0xf04))->f6(2, 0);
        ((Big*)(self + 0x19cc))->f19(3, 0);
        ((Big*)(self + 0x15c0))->f6(1);
        ((Big*)(self + 0x1d6c))->f33();
        ((Big*)(self + 0x20d0))->f33();
        ((Big*)(self + 0x1fdc))->f4();
        ((Big*)(self + 0x1aa0))->f4();
    } else {
        ((Poly8*)(self + 0xe7c))->f19(0, 0);
    }
    ((Big*)o2)->f13(0x1100000D, f31 + farg0);
    ((Big*)(self + 0xdb4))->f5(arg1);
    return 1;
}
