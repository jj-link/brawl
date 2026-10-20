#pragma force_active on
typedef struct S {
    char pad[0x188];
    int v188;
    float v18C;
} S;

extern "C" void fn_76_8E8(S* r3, int* r4, float* r5) {
    *r4 = r3->v188;
    *r5 = r3->v18C;
}
