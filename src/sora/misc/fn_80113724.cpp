#pragma force_active on
#pragma fp_contract off

struct Matrix {
    float m[3][4];
};

struct Object {
    char pad[0x54];
    unsigned char ready : 1;
    unsigned char bit6 : 1;
    unsigned char bit5 : 1;
    unsigned char bit4 : 1;
    unsigned char low : 4;
    unsigned char high55 : 2;
    unsigned char active : 1;
    unsigned char low55 : 5;
};

extern "C" void fn_80113A84(Object*, Matrix*);
extern "C" void fn_801132C4(Object*, Matrix*);
extern "C" void fn_80113000(Object*, Matrix*);
extern "C" void fn_801134A4(Object*);

extern unsigned char lbl_805A0358;
extern const float lbl_805A2940;

inline bool small(const Matrix& m) {
    return (m.m[2][0] * m.m[2][0] +
            (m.m[0][0] * m.m[0][0] + m.m[1][0] * m.m[1][0])) +
           (m.m[2][1] * m.m[2][1] +
            (m.m[0][1] * m.m[0][1] + m.m[1][1] * m.m[1][1])) <
           lbl_805A2940;
}

extern "C" void fn_80113724(Object* self, int arg) {
    Matrix m;
    if (self->active) {
        fn_80113A84(self, &m);
        if (arg != 0 || !self->ready) {
            fn_801132C4(self, &m);
            self->ready = 1;
        } else {
            fn_80113000(self, &m);
        }
        if (lbl_805A0358 && small(m)) {
            self->bit4 = 0;
            self->ready = 0;
        }
    } else {
        fn_801134A4(self);
    }
}
