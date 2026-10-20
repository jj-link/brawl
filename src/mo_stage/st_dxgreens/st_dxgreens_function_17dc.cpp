#pragma force_active on
struct S {
    char pad[0x188];
    int a;
    float b;
};

extern "C" void fn_79_17DC(S* self, int* outA, float* outB) {
    *outA = self->a;
    *outB = self->b;
}
