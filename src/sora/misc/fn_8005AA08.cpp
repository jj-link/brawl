#pragma force_active on

typedef unsigned char u8;
typedef float f32;

struct Vec3f {
    f32 x, y, z;
};

struct Matrix {
    char pad0[0x2C];
    f32 unk2C;
};

extern "C" void setSRT__6MatrixFRC5Vec3fRC5Vec3fRC5Vec3f(Matrix* self, Vec3f* a, Vec3f* b, Vec3f* c);
extern "C" void fn_8005AA94(void* arg0, Matrix* out);
extern "C" void mul__6MatrixCFPC6MatrixP6Matrix(const Matrix* self, Matrix* a, Matrix* b);

extern f32 lbl_805A18E0;

extern "C" void fn_8005AA08(void* arg0, Matrix* arg1) {
    Matrix sp8;
    u8* obj = (u8*)arg0;

    setSRT__6MatrixFRC5Vec3fRC5Vec3fRC5Vec3f(arg1, (Vec3f*)(obj + 0x3C), (Vec3f*)(obj + 0x30), (Vec3f*)(obj + 0x24));
    if (*(int*)(obj + 0x1C) != 0) {
        fn_8005AA94(arg0, &sp8);
        mul__6MatrixCFPC6MatrixP6Matrix(&sp8, arg1, arg1);
    }
    if ((obj[0x0D] >> 5) & 1) {
        arg1->unk2C *= lbl_805A18E0;
    }
}
