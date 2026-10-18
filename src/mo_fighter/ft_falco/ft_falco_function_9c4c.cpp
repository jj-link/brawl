#pragma force_active on
struct FtObj {
    void *vtbl;
    int pad[3];
    void *f10;
    void *f14;
    void *f18;
};

extern "C" {
extern unsigned char lbl_108_data_2938[];

void fn_108_9C4C(FtObj *self, void *a, void *b, void *c)
{
    self->vtbl = lbl_108_data_2938;
    self->f10 = a;
    self->f14 = b;
    self->f18 = c;
}
}
