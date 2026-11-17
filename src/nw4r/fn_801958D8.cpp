#pragma force_active on

struct Matrix {
    float m[3][4];
};

struct Obj {
    unsigned int flags;
    char pad[0x18];
    Matrix matrix;
};

extern "C" void fn_801EC158(void*);
extern "C" void fn_801EC184(const void*, void*);
extern float lbl_805A31F0;

extern "C" void fn_801958D8(const Obj* arg0, Matrix* arg1) {
    unsigned int flags = arg0->flags;

    if (flags & 0x20) {
        if (flags & 0x40) {
            fn_801EC158(arg1);
            return;
        }

        fn_801EC158(arg1);

        float c, b, a;
        a = arg0->matrix.m[0][3];
        b = arg0->matrix.m[1][3];
        c = arg0->matrix.m[2][3];

        arg1->m[0][3] = a;
        arg1->m[1][3] = b;
        arg1->m[2][3] = c;
        return;
    }

    if (flags & 0x40) {
        fn_801EC184(&arg0->matrix, arg1);

        float z = lbl_805A31F0;
        arg1->m[0][3] = z;
        arg1->m[1][3] = z;
        arg1->m[2][3] = z;
        return;
    }

    fn_801EC184(&arg0->matrix, arg1);
}
