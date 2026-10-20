#pragma force_active on
struct S {
    char pad[0x188];
    int a;
    float b;
};

extern "C" void fn_61_2158(S* s, int* out1, float* out2) {
    *out1 = s->a;
    *out2 = s->b;
}
