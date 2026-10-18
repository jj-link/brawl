#pragma force_active on
extern char lbl_27_data_731C[];

struct Fn27Obj {
    void *vt;
    short a;
    short b;
    short c;
};

extern "C" {
void fn_27_D4B40(Fn27Obj *o, short x)
{
    o->vt = lbl_27_data_731C;
    o->a = -1;
    o->b = x;
    o->c = -1;
}
}
