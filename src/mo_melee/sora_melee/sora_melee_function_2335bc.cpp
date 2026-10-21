#pragma force_active on
extern "C" {
extern unsigned int lbl_27_data_4BE88[];
void __dl__FPv(void*);
}

struct Base {
    int pad;
};

struct S : Base {
    virtual void method(int);
    virtual ~S();
};

extern "C" void* fn_27_2335BC(void* arg, int flag) {
    if (arg != 0) {
        S* p = *(S**)arg;
        *(void**)((char*)arg + 4) = &lbl_27_data_4BE88;
        if (p != 0) {
            delete p;
        }
        if (flag > 0) {
            __dl__FPv(arg);
        }
    }
    return arg;
}
