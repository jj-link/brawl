#pragma force_active on
struct Matrix {
    float m[12];
};

extern "C" void fn_27_6DC58(void*);
extern "C" void mul__6MatrixCFPC6MatrixP6Matrix(
    const Matrix*, const Matrix*, Matrix*);

struct Object {
    char pad[0x54];
    Matrix matrix;
};

extern "C" void fn_41_27B28(Object* self, Matrix* out) {
    fn_27_6DC58(self);
    mul__6MatrixCFPC6MatrixP6Matrix(out, &self->matrix, out);
}
