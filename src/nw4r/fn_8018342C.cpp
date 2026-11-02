#pragma force_active on

struct Matrix {
    float m[3][4];
};

struct Object {
    char pad[0x84];
    Matrix matrix;
};

extern float lbl_805A30B0;

struct State {
    char pad0[4];
    Matrix matrix;
    char pad34[4];
    float left;
    char pad3c[4];
    float right;
    char pad44[12];
    unsigned char flag : 1;

    bool hasFlag() const {
        return flag;
    }

    bool isNegative() const {
        return right - left < lbl_805A30B0;
    }
};

extern "C" void fn_801EC1B8(void*, void*, void*);
extern "C" void fn_801EC184(void*, void*);
extern "C" void fn_801F51DC(const Matrix*, unsigned int);
extern "C" void fn_801F52E4(unsigned int);

extern "C" void fn_8018342C(Object* object, const State* state) {
    Matrix temp;
    const Matrix* result;

    if (state->hasFlag()) {
        fn_801EC1B8((void*)&state->matrix, &object->matrix, &temp);
        if (state->isNegative()) {
            temp.m[0][1] = -temp.m[0][1];
            temp.m[1][1] = -temp.m[1][1];
            temp.m[2][1] = -temp.m[2][1];
        }
        result = &temp;
    } else if (state->isNegative()) {
        fn_801EC184((void*)&object->matrix, &temp);
        temp.m[0][1] = -temp.m[0][1];
        temp.m[1][1] = -temp.m[1][1];
        temp.m[2][1] = -temp.m[2][1];
        result = &temp;
    } else {
        result = &object->matrix;
    }

    fn_801F51DC(result, 0);
    fn_801F52E4(0);
}
