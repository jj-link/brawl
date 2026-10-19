#pragma force_active on
extern "C" void fn_108_7F30(void* self, int arg);
extern "C" unsigned char lbl_108_data_79B8[];

struct Fn108Obj {
    void* vtable;
    unsigned char pad[4];
    void* parameters;
    int index;
};

extern "C" Fn108Obj* fn_108_1070C(Fn108Obj* self, void* parameters) {
    fn_108_7F30(self, 0);
    self->vtable = lbl_108_data_79B8;
    self->parameters = parameters;
    self->index = -1;
    return self;
}
