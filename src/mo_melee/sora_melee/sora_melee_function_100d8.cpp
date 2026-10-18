#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 a;
    u32 b;
    void* c;
    void* d;
};

extern char lbl_27_data_D68[];

extern "C" void fn_27_100D8(Obj* self, void* arg) {
    self->a = 0;
    self->b = 0;
    self->c = lbl_27_data_D68;
    self->d = arg;
}
