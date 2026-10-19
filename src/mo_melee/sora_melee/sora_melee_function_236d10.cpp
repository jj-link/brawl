#pragma force_active on
extern float lbl_27_data_547E0;

struct fn27_236D10_Obj {
    char pad0[8];
    unsigned char* flag;
    char pad1[4];
    float a;
    float b;
};

extern "C" void fn_27_236D10(fn27_236D10_Obj* self) {
    if (self->b >= self->a) {
        *self->flag = 1;
    }
    float c = lbl_27_data_547E0;
    self->b = self->b + c;
}
