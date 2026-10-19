#pragma force_active on
struct SnakeSupport;

extern "C" {
extern char lbl_27_data_458C0[];
SnakeSupport* fn_122_177A8(SnakeSupport* self, int val);
}

struct SnakeSupport {
    char* vtbl;
    int pad4;
    float f8;
    float fc;
    float f10;
};

extern "C" {
SnakeSupport* fn_122_2455C(SnakeSupport* self, float a, float b, float c) {
    fn_122_177A8(self, 0);
    self->vtbl = lbl_27_data_458C0;
    self->f8 = a;
    self->fc = b;
    self->f10 = c;
    return self;
}
}
