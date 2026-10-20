#pragma force_active on
extern "C" void* fn_62_82F4(void* self, void* a, void* b);

struct A {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25();
    virtual void* f(void*, void*);
};

struct B {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25();
    virtual void* f(void*);
};

extern "C" void* fn_62_82F4(void* self, void* a, void* b) {
    void* src = ((A*)self)->f(a, b);
    void* result = ((B*)self)->f(b);
    struct S { unsigned long a, b; };
    *(S*)result = *(S*)src;
    return result;
}
