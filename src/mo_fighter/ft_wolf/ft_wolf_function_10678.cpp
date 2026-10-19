#pragma force_active on
extern "C" void fn_125_7F88(void* self, unsigned char v);
extern "C" unsigned char lbl_125_data_7A04[];

struct Obj {
    void* vtable;
    int pad;
    void* param;
    int index;
};

extern "C" Obj* fn_125_10678(Obj* self, void* param) {
    fn_125_7F88(self, 0);
    self->vtable = lbl_125_data_7A04;
    self->param = param;
    self->index = -1;
    return self;
}
