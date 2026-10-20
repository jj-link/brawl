#pragma force_active on
extern char lbl_27_data_C78[];

struct fn_27_FED0_obj {
    char* vtbl;
    unsigned int field;
};

extern "C" void fn_27_FED0(fn_27_FED0_obj* self, unsigned int v)
{
    self->field = v;
    self->vtbl = lbl_27_data_C78;
}
