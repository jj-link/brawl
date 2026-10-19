#pragma force_active on
extern char lbl_116_data_26F0[];

typedef struct FtPokeObj {
    void *vtbl;
    int pad04[3];
    void *f10;
    void *f14;
    void *f18;
} FtPokeObj;

extern "C" void fn_116_8FCC(FtPokeObj *self, void *a, void *b, void *c)
{
    self->vtbl = lbl_116_data_26F0;
    self->f10 = a;
    self->f14 = b;
    self->f18 = c;
}
