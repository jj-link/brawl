#pragma force_active on
#pragma fp_contract on

struct Vec4 {
    float x, y, z, w;
};

struct Matrix {
    float m[4][4];
} __attribute__((aligned(16)));

struct Object {
    Vec4* shape;
    void* unk4;
    Matrix* transform;
};

extern "C" void fn_80287600(Matrix*, const Matrix*, const Matrix*);
extern "C" void fn_803198C8(void*, Vec4*, Vec4*, Matrix*, Vec4*);
extern const float lbl_805A3F38;

extern "C" void fn_802B1B3C(Object* a, Object* b, void* c, Vec4* out) {
    Matrix matrix;
    Vec4 v;
    Vec4* sa = a->shape;
    Vec4* sb = b->shape;

    fn_80287600(&matrix, a->transform, b->transform);
    fn_803198C8(c, sa, sb, &matrix, &v);

    Matrix* m = a->transform;
    float x = v.x, y = v.y, z = v.z;

    out->x = z * m->m[2][0] + (x * m->m[0][0] + y * m->m[1][0]);
    out->y = z * m->m[2][1] + (x * m->m[0][1] + y * m->m[1][1]);
    out->z = z * m->m[2][2] + (x * m->m[0][2] + y * m->m[1][2]);
    out->w = lbl_805A3F38;

    float ra = sa->w;
    float rb = sb->w;
    out->w = (v.w - ra) - rb;
}
