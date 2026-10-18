#pragma force_active on
extern "C" {
extern char lbl_27_data_21018[];
}

struct Fn27D3B18Obj {
    void *vtbl;
    short a;
    short b;
    short c;
};

extern "C" void fn_27_D3B18(Fn27D3B18Obj *p, short x) {
    p->a = -1;
    p->vtbl = lbl_27_data_21018;
    p->b = x;
    p->c = -1;
}
