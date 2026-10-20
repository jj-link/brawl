#pragma force_active on
extern "C" {
extern char lbl_27_data_CF0[];
}

struct Fn27Obj {
    void *vtbl;
    void *arg;
};

extern "C" void fn_27_FFF8(Fn27Obj *self, void *arg)
{
    self->arg = arg;
    self->vtbl = lbl_27_data_CF0;
}
