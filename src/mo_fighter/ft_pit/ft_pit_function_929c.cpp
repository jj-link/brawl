#pragma force_active on
typedef struct Obj {
    void *vtbl;
    int unk04;
    int unk08;
    int unk0C;
    void *f10;
    void *f14;
    void *f18;
} Obj;

extern "C" {
extern char lbl_112_data_217C[];
}

extern "C" void fn_112_929C(Obj *self, void *a, void *b, void *c)
{
    self->vtbl = lbl_112_data_217C;
    self->f10 = a;
    self->f14 = b;
    self->f18 = c;
}
