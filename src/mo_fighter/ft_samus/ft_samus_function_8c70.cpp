#pragma force_active on
extern "C" {
extern char lbl_94_data_4A00[];

typedef struct FtObj {
    void *vtbl;
    char pad[0xC];
    void *f10;
    void *f14;
    void *f18;
} FtObj;

void fn_94_8C70(FtObj *self, void *a, void *b, void *c)
{
    self->vtbl = lbl_94_data_4A00;
    self->f10 = a;
    self->f14 = b;
    self->f18 = c;
}
}
