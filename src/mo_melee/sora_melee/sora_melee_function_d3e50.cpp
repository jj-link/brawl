#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;

extern "C" {
extern u8 lbl_27_data_1180[];

struct Fn27Obj {
    void *ptr;
    s16 f4;
    s16 f6;
    s16 f8;
};

void fn_27_D3E50(Fn27Obj *self, s16 arg) {
    self->f4 = -1;
    self->ptr = lbl_27_data_1180;
    self->f6 = arg;
    self->f8 = -1;
}
}
