#pragma force_active on
extern "C" {
extern char lbl_80487914[];

struct Fn2D92B0Obj {
    void *vtbl;
    short a;
    short b;
    void *c;
};

void fn_802D92B0(Fn2D92B0Obj *p, void *x) {
    p->vtbl = lbl_80487914;
    p->b = 1;
    p->c = x;
}
}
