#pragma force_active on
extern "C" {
extern char lbl_804886A8[];

struct Fn802F3420Obj {
    void *ptr;
    short a;
    short b;
    int c;
};

void fn_802F3420(Fn802F3420Obj *self, int arg) {
    self->b = 1;
    self->ptr = lbl_804886A8;
    self->c = arg;
}
}
