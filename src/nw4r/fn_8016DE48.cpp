#pragma force_active on

struct Matrix {
    float m[3][4];
};

struct Object {
    char pad0[0x20];
    void* field20;
    char pad24[4];
    unsigned int flags;
    char pad2C[0x5C];
    signed char field88;
    char field89;
    unsigned char dirty;
    char field8B;
    Matrix matrix;
};

extern "C" void fn_80166B8C(void*, Matrix*);
extern "C" void fn_801669EC(Matrix*, Matrix*, unsigned int, unsigned int, signed char);

extern "C" Matrix* fn_8016DE48(Object* self, Matrix* out) {
    if (self->dirty) {
        Matrix b;
        fn_80166B8C(self->field20, &b);
        fn_801669EC(&self->matrix, &b, self->flags & 1,
                    (self->flags >> 1) & 1, self->field88);
        self->dirty = 0;
    }
    *out = self->matrix;
    return out;
}
