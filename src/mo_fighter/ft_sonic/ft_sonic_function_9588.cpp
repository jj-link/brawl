#pragma force_active on
struct Obj {
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
    virtual void f12(void*, void*);
};

extern "C" void* fn_27_135EDC(void*);
extern "C" Obj* fn_123_8DCC(void*);

extern "C" void fn_123_9588(void* self, void* a, void* b) {
    Obj* obj = fn_123_8DCC(fn_27_135EDC(self));
    obj->f12(a, b);
}
