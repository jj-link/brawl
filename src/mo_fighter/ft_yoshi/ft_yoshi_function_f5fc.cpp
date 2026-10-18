#pragma force_active on
extern "C" unsigned char lbl_95_data_7C70[];

struct FnObj {
    void* vtable;
    void* field;
};

extern "C" void fn_95_F5FC(FnObj* self, void* value) {
    self->field = value;
    self->vtable = lbl_95_data_7C70;
}
