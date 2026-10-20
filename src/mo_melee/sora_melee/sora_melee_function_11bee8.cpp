#pragma force_active on
typedef unsigned int u32;

class fnObj {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25();
    virtual void* f26(void* a);
};

extern "C" {
void fn_27_11BEE8(fnObj* self, void* unused, void* arg) {
    void* p = self->f26(unused);
    void* q = self->f26(arg);
    *(u32*)q = *(u32*)p;
}
}
