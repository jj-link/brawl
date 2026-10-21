#pragma force_active on

struct Query {
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
    virtual int get();
};

struct Mid {
    char pad[0x70];
    Query* q;
};

struct Outer {
    char pad[0xD8];
    Mid* mid;
};

extern "C" char lbl_27_bss_8094[];
extern "C" int fn_27_3580FC(void*, void*, void*, void*, void*);
extern "C" void fn_27_1324D4(void*, void*, void*, void*, void*);

extern "C" void fn_110_1F164(void* a, void* b, Outer* c, void* d, void* e) {
    int status = c->mid->q->get();
    if (status == 0x116) {
        fn_27_1324D4(a, b, c, d, e);
    } else if (fn_27_3580FC(lbl_27_bss_8094, b, c, d, e) == 0) {
        fn_27_1324D4(a, b, c, d, e);
    }
}
