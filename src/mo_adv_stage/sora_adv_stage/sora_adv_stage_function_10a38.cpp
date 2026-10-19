#pragma force_active on
typedef unsigned char u8;

struct Obj {
    int f00;
    void *f04;
    int f08;
    u8 f0c;
    int f10;
    u8 f14;
    int f18;
    int f1c;
};

extern int lbl_40_data_1E78[];

extern "C" void fn_40_10A38(Obj *p, int a4, int a5, u8 a6, int a7)
{
    p->f00 = 0;
    p->f08 = 0;
    p->f04 = lbl_40_data_1E78;
    p->f0c = 1;
    p->f10 = a5;
    p->f14 = a6;
    p->f18 = a7;
    p->f1c = a4;
}
