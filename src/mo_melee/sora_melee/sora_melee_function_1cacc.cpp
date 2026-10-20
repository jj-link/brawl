#pragma force_active on
struct fn_27_Obj {
    char pad[0x148];
    void *field;
};

extern "C" {
void *fn_27_1CACC(fn_27_Obj *self, void *value)
{
    void *old = self->field;
    self->field = value;
    return old;
}
}
