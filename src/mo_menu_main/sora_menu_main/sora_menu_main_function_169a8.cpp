#pragma force_active on
typedef unsigned int u32;

class VObj {
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
    virtual void v11();
    virtual void v12();
    virtual void v15(u32 arg);
};

class FinalObj {
public:
    char pad[0x3c];
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
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};

extern "C" void fn_2_169A8(char* self) {
    u32 i;
    for (i = 0; i < 3; i++) {
        VObj* o = *(VObj**)(self + 0x654);
        char* base = *(char**)(self + 0x64c);
        char* e = *(char**)(base + i * 4 + 0x48);
        u32 arg = *(u32*)(e + 0x10);
        o->v15(arg);
    }

    FinalObj* x = *(FinalObj**)(self + 0x66c);
    if (x != 0) {
        x->f23();
        *(void**)(self + 0x66c) = 0;
    }
}
