#pragma force_active on
struct FnObj27 {
    char pad[0x20];
    float f0;
    float f1;
    float f2;
    int i0;
};

extern "C" {
void fn_27_302B8(FnObj27* self, float a, float b, float c, int d) {
    self->f0 = a;
    self->f1 = b;
    self->f2 = c;
    self->i0 = d;
}
}
