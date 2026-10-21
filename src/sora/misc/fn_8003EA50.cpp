#pragma force_active on
struct Matrix {
    float m[12];
};

struct Vec3 {
    float x, y, z;
};

extern "C" void fn_8003ECA0(Matrix*, float, float, float);
extern "C" void mul__6MatrixCFPC6MatrixP6Matrix(
    const Matrix*, const Matrix*, Matrix*);

extern "C" void fn_8003EA50(Matrix* self, const Vec3* v) {
    Matrix temp;
    fn_8003ECA0(&temp, v->x, v->y, v->z);
    mul__6MatrixCFPC6MatrixP6Matrix(self, &temp, self);
}
