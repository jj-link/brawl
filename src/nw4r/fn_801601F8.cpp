#pragma force_active on
struct S {
    char pad[0x4C];
    float a, b, c;
    int d, e;
    int* f;
};
extern "C" void fn_8015E8F4(S*);
extern "C" float lbl_805A2BDC;
extern "C" float lbl_805A2BD8;
extern "C" int lbl_805A04B4;
extern "C" S* fn_801601F8(S* self) {
    fn_8015E8F4(self);
    float value = lbl_805A2BDC;
    self->b = value;
    float other = 3.4028234663852886e+38f;
    self->a = other;
    self->c = value;
    self->d = 4;
    self->e = 0;
    self->f = &lbl_805A04B4;
    return self;
}