#pragma force_active on

extern "C" void __dl__FPv(void*);
extern unsigned int lbl_27_data_4BE88[];

struct Base {
    int pad;
};

struct S : Base {
    virtual void vf0();
    virtual void method(int);
    virtual ~S();
};

struct Obj {
    S* ptr;
    void* vtable;
};

extern "C" Obj* fn_27_236ED0(Obj* arg, int flag) {
    if (arg != 0) {
        if (arg != 0) {
            S* p = arg->ptr;
            arg->vtable = &lbl_27_data_4BE88;
            if (p != 0 && p != 0) {
                p->method(1);
            }
        }
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
