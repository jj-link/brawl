#pragma force_active on

struct V3 {
    float x, y, z;
};

struct Bits {
    unsigned int a : 7;
    unsigned int b : 5;
    unsigned int c : 3;
    unsigned int d : 1;
    unsigned int e : 1;
    unsigned int f : 6;
    unsigned int g : 9;
};

struct Local {
    int a;
    int b;
    int c;
    int d;
    int e;
    V3 pos;
    Bits bits;
};

extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern float lbl_41_rodata_14;

struct V64 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual unsigned int get(unsigned int);
};

struct V1C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void set(int, int, int*);
    virtual void f10();
    virtual void apply(int, int, unsigned int, int, int);
};

struct Mod {
    char pad0[0x1c];
    V1C* m1c;
    char pad1[0x64 - 0x20];
    V64* m64;
};

extern "C" void fn_41_5C54(char* self) {
    Local l;
    if ((*(Mod**)(self + 0x1b4))->m64->get(0x12000010) == 1U) {
        l.pos.x = lbl_41_rodata_14;
        l.pos.y = lbl_41_rodata_14;
        l.pos.z = lbl_41_rodata_14;
        l.bits.f = 0;
        l.a = 0;
        l.b = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(self + 0xdc, 0x59f6, 0);
        l.c = 0;
        l.d = 0;
        l.e = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(self + 0xdc, 0x59f5, 0);
        l.bits.a = 0;
        l.bits.b = 1;
        l.bits.c = 4;
        l.bits.d = 1;
        l.bits.e = 1;
        unsigned int v = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(self + 0xdc, 0x59e6, 0);
        (*(Mod**)(self + 0x1b4))->m1c->set(0, 0, &l.a);
        (*(Mod**)(self + 0x1b4))->m1c->apply(0, v, *(unsigned int*)(self + 0x28), 0, 0);
    }
}
