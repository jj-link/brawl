#pragma force_active on
extern "C" {
extern void fn_801AC1AC(void*, int);
extern char lbl_804664F8[];

struct Sub {
    virtual void m0();
    virtual void m1(int, int, void*);
};

struct Obj {
    void* vtbl;
    char pad[0xE8 - 4];
    Sub* sub;
};

void* fn_801B54A4(Obj* arg0) {
    if (arg0 != 0) {
        Sub* sub = arg0->sub;
        *(char**)arg0 = lbl_804664F8;
        if (sub != 0) {
            sub->m1(0x10003, 0, arg0);
        }
        fn_801AC1AC(arg0, 0);
    }
    return arg0;
}
}
