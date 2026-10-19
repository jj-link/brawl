#pragma force_active on
struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void call(void*);
};

extern "C" {
void* fn_96_1D7E4(void* p);

void fn_96_1DC8C(void* p) {
    void* obj = fn_96_1D7E4(p);
    if (obj) {
        ((Obj*)obj)->call(*(void**)((char*)p + 8));
    }
}
}
