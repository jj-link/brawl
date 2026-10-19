#pragma force_active on
class ClassA {
public:
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
    virtual int target(int arg);
};

class ClassB {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void* target();
};

extern "C" void* fn_118_D94C(void* a, void* b) {
    ClassA* inner_a = *(ClassA**)((char*)*(void**)((char*)b + 0xD8) + 0x64);
    int result = inner_a->target(0x22000011);
    if (result != 0) return 0;
    ClassB* inner_b = *(ClassB**)((char*)*(void**)((char*)b + 0xD8) + 0x3C);
    return inner_b->target();
}
