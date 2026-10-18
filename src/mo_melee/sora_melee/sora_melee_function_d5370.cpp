#pragma force_active on
extern "C" {
struct Fn27Obj {
    void *vtbl;
    short a;
    short b;
    short c;
};

extern char lbl_27_data_21024[];

void fn_27_D5370(Fn27Obj *self, short v)
{
    self->a = -1;
    self->vtbl = lbl_27_data_21024;
    self->b = v;
    self->c = -1;
}
}
