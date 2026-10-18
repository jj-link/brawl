#pragma force_active on
extern "C" char lbl_109_data_1B00[];

struct FtObj {
    void *vtbl;
    int pad[3];
    void *f10;
    void *f14;
    void *f18;
};

extern "C" {
void fn_109_82A8(FtObj *p, void *a, void *b, void *c)
{
    p->vtbl = lbl_109_data_1B00;
    p->f10 = a;
    p->f14 = b;
    p->f18 = c;
}
}
