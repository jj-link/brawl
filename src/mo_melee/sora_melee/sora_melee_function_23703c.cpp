#pragma force_active on
extern "C" {
extern unsigned int lbl_27_data_4BE88[];
void __dl__FPv(void*);
}

struct Base {
    int pad;
};

struct S : Base {
    virtual void vf0();
    virtual void method(int);
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual ~S();
};

extern "C" void* fn_27_23703C(void* arg, int flag) {
    if (arg != 0) {
        if (arg != 0) {
            S* p = *(S**)arg;
            *(void**)((char*)arg + 4) = &lbl_27_data_4BE88;
            if (p != 0) {
                if (p != 0) {
                    p->method(1);
                }
            }
        }
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
