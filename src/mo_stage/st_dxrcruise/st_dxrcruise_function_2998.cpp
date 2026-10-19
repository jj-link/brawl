#pragma force_active on
struct Obj80_2998 {
    char pad[0x188];
    int a;
    float b;
};

extern "C" void fn_80_2998(Obj80_2998* self, int* outA, float* outB) {
    *outA = self->a;
    *outB = self->b;
}
