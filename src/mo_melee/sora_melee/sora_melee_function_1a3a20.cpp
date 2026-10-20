#pragma force_active on
extern char lbl_27_data_364A8[];

struct fn_27_1A3A20_Obj {
    void *ptr0;
    void *ptr4;
    unsigned int flag;
};

extern "C" {
void fn_27_1A3A20(fn_27_1A3A20_Obj *self)
{
    unsigned int f = self->flag;
    char *base = lbl_27_data_364A8;
    self->ptr0 = base;
    self->ptr4 = base + 0x48;
    self->flag = f & 1;
}
}
