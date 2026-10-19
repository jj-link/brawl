#pragma force_active on
typedef struct Obj {
    void *vtbl;
    int pad[3];
    int f10;
    int f14;
    int f18;
} Obj;

extern void *lbl_121_data_36E0[];

extern "C" void fn_121_8870(Obj *o, int a, int b, int c)
{
    o->vtbl = (void *)lbl_121_data_36E0;
    o->f10 = a;
    o->f14 = b;
    o->f18 = c;
}
