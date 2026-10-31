#pragma force_active on
extern "C" const float lbl_77_rodata_0[];
extern "C" void fn_27_233C70(void*, void*);
struct S {
    char pad0[0x9c];
    float* d;
    char pad1[0x13c];
    float b;
    char pad2[8];
    float c;
    float c2;
    char pad3[4];
    void* e;
    void* f;
};
extern "C" void fn_77_B08(S* o) {
    const float* ro = lbl_77_rodata_0;
    if (!o->e) return;
    float* u = (float*)o->f;
    if (!u) return;
    float* d = o->d;
    if (!d) return;
    u[8] = ro[2] + (o->c - o->b);
    float y = ro[3] + (*d - o->c2);
    u[9] = y;
    u[6] = ro[0];
    u[7] = *d - ro[7] * y;
    fn_27_233C70(o->e, o->f);
}
