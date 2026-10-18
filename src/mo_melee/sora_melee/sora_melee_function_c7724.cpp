#pragma force_active on
extern "C" char lbl_27_data_20878[];

struct S {
    void* vt;
    int a;
    int b;
    int c;
};

extern "C" void fn_27_C7724(S* p) {
    p->a = 0;
    p->vt = lbl_27_data_20878;
    p->b = 0;
    p->c = 0;
}
