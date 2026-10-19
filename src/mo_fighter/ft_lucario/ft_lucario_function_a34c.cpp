#pragma force_active on
struct A {
    void* a;
    void* b;
};

struct B : A {
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
    virtual void f20(void*, void*);
    virtual void f21(void*, void*);
    virtual unsigned int f22(void*, void*);
};

extern "C" unsigned int fn_118_A34C(B* obj, void* arg2, void* arg3) {
    unsigned int result = obj->f22(arg2, arg3);
    if (result == 1) {
        obj->f20(arg2, arg3);
    }
    return result;
}
