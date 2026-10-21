#pragma force_active on

extern "C" {
void __dl__FPv(void*);
extern unsigned int lbl_27_data_4BE88[];
}

struct Base {
    int unk0;
};

struct Sub : Base {
    virtual void vf0();
    virtual void vf1(int);
    virtual void vf2();
    virtual void vf3();
};

extern "C" void* fn_27_2370C4(Sub** arg, int flag) {
    if (arg != 0) {
        if (arg != 0) {
            Sub* p = *arg;
            *(void**)((char*)arg + 4) = &lbl_27_data_4BE88;
            if (p != 0) {
                if (p != 0) {
                    p->vf1(1);
                }
            }
        }
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
