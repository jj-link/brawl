#pragma force_active on
extern "C" char lbl_108_data_303C[];

struct Fn108Obj {
    void* p0;
    char b4;
};

extern "C" void fn_108_7F30(Fn108Obj* self, int arg) {
    self->p0 = lbl_108_data_303C;
    self->b4 = arg;
}