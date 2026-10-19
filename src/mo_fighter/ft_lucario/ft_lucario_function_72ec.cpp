#pragma force_active on
extern "C" {
extern char lbl_27_data_8E80[];
}

struct LucarioObj {
    void *vtbl;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
};

extern "C" void fn_118_72EC(LucarioObj *self, int arg)
{
    int buf[2];
    int *p = buf;
    int z = 0;
    self->vtbl = lbl_27_data_8E80;
    self->field04 = arg;
    self->field08 = z;
    p[0] = z;
    self->field0C = -1;
    self->field10 = -1;
    self->field14 = p[0];
}
