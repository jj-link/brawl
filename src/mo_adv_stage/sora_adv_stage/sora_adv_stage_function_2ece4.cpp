#pragma force_active on
extern "C" {
void fn_27_26DDB0(void*, float (*)[4]);
void startGimmickSE__9grGimmickFUl(void*, unsigned long);
void startGimmickEffect__9grGimmickFUl(void*, unsigned long);
}

struct Vec3 {
    float x, y, z;

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

extern "C" void fn_40_2ECE4(void* self) {
    float matrix[3][4];
    fn_27_26DDB0(self, matrix);

    float z = matrix[2][3];
    float y = matrix[1][3];
    float x = matrix[0][3];
    Vec3 pos(x, y, z);

    startGimmickSE__9grGimmickFUl(self, 0);
    startGimmickEffect__9grGimmickFUl(self, 0);
}
