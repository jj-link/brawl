#pragma force_active on
struct S {
    char pad[0x30];
    float f0;
    float f4;
};

extern "C" void fn_27_B6D78(S* self, float a, float b) {
    self->f0 = a;
    self->f4 = b;
}
