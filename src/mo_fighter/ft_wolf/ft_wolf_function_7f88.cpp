#pragma force_active on
extern "C" {
extern char lbl_125_data_3038[];

typedef struct Obj {
    void *vtbl;
    unsigned char flag;
} Obj;

void fn_125_7F88(Obj *self, unsigned char v)
{
    self->vtbl = lbl_125_data_3038;
    self->flag = v;
}
}
