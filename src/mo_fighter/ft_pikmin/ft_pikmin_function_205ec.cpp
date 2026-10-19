#pragma force_active on
struct FnObj;

struct PikminObj {
    void* vtbl;
    int pad4;
    float f8;
    float fc;
    float f10;
};

extern "C" {
extern FnObj* fn_113_1C230(FnObj* obj, int value);
extern char lbl_27_data_458C0[];
}

extern "C" PikminObj* fn_113_205EC(PikminObj* self, float a, float b, float c) {
    fn_113_1C230((FnObj*)self, 0);
    self->vtbl = lbl_27_data_458C0;
    self->f8 = a;
    self->fc = b;
    self->f10 = c;
    return self;
}
