#pragma force_active on
extern "C" char lbl_27_data_1F88[];

struct fn_27_C2DA4_Obj {
    void* vtbl;
    int a;
    int b;
    int c;
};

extern "C" void fn_27_C2DA4(fn_27_C2DA4_Obj* p) {
    p->a = 0;
    p->vtbl = lbl_27_data_1F88;
    p->b = 0;
    p->c = 0;
}
