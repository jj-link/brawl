#pragma force_active on
struct Obj {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25();
    virtual unsigned int* get(void* a);
};

extern "C" void fn_78_7964(Obj* self, void* unused, void* arg) {
    unsigned int* s = self->get(unused);
    unsigned int* dst = self->get(arg);
    dst[0] = s[0];
    dst[1] = s[1];
}
