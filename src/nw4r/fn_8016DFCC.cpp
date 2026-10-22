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
extern "C" void fn_801EC41C(Matrix*, Matrix*);
extern "C" void fn_801EC1B8(Matrix*, Matrix*, Matrix*);
extern Matrix lbl_804A3E40;

extern "C" void fn_8016DFCC(Object* self) {
    Matrix a;
    Matrix c;
    fn_80166B8C(self->field20, &a);

    if (self->dirty) {
        Matrix b;
        fn_80166B8C(self->field20, &b);
        fn_801669EC(&self->matrix, &b, self->flags & 1,
                    (self->flags >> 1) & 1, self->field88);
        self->dirty = 0;
    }

    c = self->matrix;
    fn_801EC41C(&a, &a);
    fn_801EC1B8(&a, &c, &lbl_804A3E40);
}
