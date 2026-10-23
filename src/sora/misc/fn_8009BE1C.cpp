#pragma force_active on

struct Obj {
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
};

extern "C" {

extern void* lbl_805A0278;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8009BE7C(void*);

void* fn_8009BE1C(void) {
    if (lbl_805A0278 == 0) {
        Obj* p = (Obj*)__nw__FUlQ25Heaps8HeapType(0x1a4, 2);
        if (p != 0) {
            p = (Obj*)fn_8009BE7C(p);
        }
        lbl_805A0278 = p;
        p->f21();
    }
    return lbl_805A0278;
}

}
