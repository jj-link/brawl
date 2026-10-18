#pragma force_active on
extern "C" {
extern char lbl_92_data_2400[];
}

struct FtObj {
    void *vtbl;
    unsigned char flag;
};

extern "C" void fn_92_6DC4(FtObj *self, unsigned char v)
{
    self->vtbl = lbl_92_data_2400;
    self->flag = v;
}
