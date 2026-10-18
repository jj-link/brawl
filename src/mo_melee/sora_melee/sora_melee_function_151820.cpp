#include <types.h>
#pragma force_active on

extern "C" void fn_27_62CB0(void*, void*);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);

class VA {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m62(int, int);
};

struct Inner {
    char pad[0x5c];
    VA* va;
};

extern "C" void fn_27_151820(void* self, void* p) {
    fn_27_62CB0(self, p);
    Inner* r6 = *(Inner**)((char*)p + 0xd8);
    VA* va = r6->va;
    int v = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(p, 0x5a02, 0);
    va->m62(v, 1);
}
