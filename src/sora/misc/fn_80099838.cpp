#pragma force_active on
#pragma fp_contract off
extern const float lbl_805A1D44;
extern const float lbl_805A1D54;
extern const float lbl_805A1D58;
extern "C" double __frsqrte(double);
extern "C" void** fn_8032EF00(void*);
extern "C" void fn_80284DB0(void*, float*);
extern "C" void fn_80283D7C(float*, const float*);

extern "C" void fn_80099838(void* self, void* arg) {
    float output[16] __attribute__((aligned(16)));
    float input[16];
    char* p = (char*)self;
    fn_80284DB0((char*)*fn_8032EF00(arg) + *(short*)(p + 0x18) * 0x30, input);
    fn_80283D7C(output, input);
    float* v = (float*)(p + 0x100);
    v[0] = output[4];
    v[1] = output[5];
    v[2] = output[6];
    v[3] = output[7];
    float s = v[2] * v[2] + (v[0] * v[0] + v[1] * v[1]);
    float scale = lbl_805A1D44;
    if (s != lbl_805A1D44) {
        if (s <= lbl_805A1D44) {
            union { unsigned int i; float f; } u;
            u.i = 0x7F800000;
            scale = u.f;
        } else {
            float r = (float)__frsqrte(s);
            scale = (lbl_805A1D54 * r) * (lbl_805A1D58 - r * (s * r));
        }
    }
    v[0] = v[0] * scale;
    v[1] = v[1] * scale;
    v[2] = v[2] * scale;
    v[3] = v[3] * scale;
    if (*(int*)(p + 0x10) == 1) {
        v[0] = -v[0];
        v[1] = -v[1];
        v[2] = -v[2];
        v[3] = -v[3];
    }
}
