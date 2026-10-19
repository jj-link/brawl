#pragma force_active on
typedef struct FtObj {
    void *vtbl;
    int pad[3];
    void *f10;
    void *f14;
    void *f18;
} FtObj;

extern char lbl_110_data_1B1C[];

extern "C" {
void fn_110_88DC(FtObj *self, void *a, void *b, void *c)
{
    self->vtbl = lbl_110_data_1B1C;
    self->f10 = a;
    self->f14 = b;
    self->f18 = c;
}
}
