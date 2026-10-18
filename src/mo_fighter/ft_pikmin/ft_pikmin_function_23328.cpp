#pragma force_active on
extern "C" unsigned char lbl_113_data_AA80[];

struct Obj {
    void* vtable;
    unsigned char flag;
};

extern "C" void fn_113_23328(Obj* self) {
    self->flag = 0;
    self->vtable = lbl_113_data_AA80;
}
