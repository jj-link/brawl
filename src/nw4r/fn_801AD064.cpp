#pragma force_active on
extern "C" {
extern void fn_801AC1AC(void*, int);
extern char lbl_80466318[];

struct Sub {
    virtual void m0();
    virtual void m1(int, int, void*);
};

void* fn_801AD064(void* arg0) {
    if (arg0 != 0) {
        Sub* sub = *(Sub**)((char*)arg0 + 0x2888);
        *(char**)arg0 = lbl_80466318;
        if (sub != 0) {
            sub->m1(0x10003, 0, arg0);
        }
        fn_801AC1AC(arg0, 0);
    }
    return arg0;
}
}
