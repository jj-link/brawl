#pragma force_active on
extern unsigned char lbl_27_data_54C18[0x20];

struct Obj {
    unsigned char* vtable;
    unsigned char* arr;
};

extern "C" {
Obj* fn_27_262230(Obj* self, int flag) {
    if (self) {
        self->vtable = lbl_27_data_54C18;
        if (self->arr) {
            if (self->arr) {
                delete[] (self->arr - 0x10);
            }
            self->arr = 0;
        }
        if (flag > 0) {
            delete self;
        }
    }
    return self;
}
}
