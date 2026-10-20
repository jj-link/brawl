#pragma force_active on
struct fn_27_Obj {
    char pad[0x160];
    void *m160;
    void *m164;
};

extern "C" {
void fn_27_150D8C(fn_27_Obj *self)
{
    self->m160 = self->m164;
    self->m164 = 0;
}
}
