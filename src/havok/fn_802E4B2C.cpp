#pragma force_active on
struct Arg0 {
    char pad[0xD0];
    float x;
    float y;
    float z;
};

struct Matrix {
    float m[12];
};

extern const float lbl_805A43C0;
extern const float lbl_805A43C4;

extern "C" void fn_80283A68(Matrix* dst, void* src);

static inline void setDiag(Matrix* matrix, float x, float y, float z) {
    __attribute__((aligned(16))) float scratch[4];
    float zero = lbl_805A43C4;
    scratch[3] = zero;
    scratch[2] = zero;
    scratch[1] = zero;
    scratch[0] = zero;
    matrix->m[1] = zero;
    matrix->m[2] = zero;
    matrix->m[3] = zero;
    matrix->m[4] = zero;
    matrix->m[6] = zero;
    matrix->m[7] = zero;
    matrix->m[8] = zero;
    matrix->m[9] = zero;
    matrix->m[11] = zero;
    matrix->m[0] = x;
    matrix->m[5] = y;
    matrix->m[10] = z;
}

extern "C" void fn_802E4B2C(Arg0* arg0, Matrix* matrix) {
    float dx = arg0->x;
    float dz;
    float dy;
    dy = arg0->y;
    dz = arg0->z;
    float one = lbl_805A43C0;
    float x = one / dx;
    float y = one / dy;
    float z = one / dz;
    setDiag(matrix, x, y, z);
    void* src = (char*)arg0 + 0x10;
    Matrix* dst = matrix;
    fn_80283A68(dst, src);
}
