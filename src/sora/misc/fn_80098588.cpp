#pragma force_active on

struct Outer {
    char pad0[8];
    float** m8;
};

extern "C" void fn_80099734(float*, float*, float*);
extern "C" void fn_80099810(float*);

extern "C" void fn_80098588(Outer* self, int idx, float* a) {
    fn_80099734(self->m8[idx], a, a);
    fn_80099810(self->m8[idx]);
}
