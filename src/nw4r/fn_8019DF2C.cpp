#pragma force_active on

extern const float lbl_805A330C;

extern "C" void fn_801F5304(float*, void*, int);

extern "C" void fn_8019DF2C(const float* p, void* q) {
    float a[12] = {
        p[0], p[1], p[2], lbl_805A330C,
        p[3], p[4], p[5], lbl_805A330C,
        p[6], p[7], p[8], lbl_805A330C
    };
    fn_801F5304(a, q, 0);
}
