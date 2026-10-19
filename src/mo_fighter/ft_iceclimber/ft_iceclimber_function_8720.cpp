#pragma force_active on
extern char lbl_27_data_8E80[];

struct FtObj {
    void *vtbl;
    void *arg4;
    int f8;
    int fC;
    int f10;
    int f14;
};

extern "C" {
void fn_105_8720(FtObj *self, void *arg)
{
    int tmp[2];
    int *p = tmp;
    self->vtbl = lbl_27_data_8E80;
    self->arg4 = arg;
    self->f8 = 0;
    p[0] = 0;
    self->fC = -1;
    self->f10 = -1;
    self->f14 = p[0];
}
}
