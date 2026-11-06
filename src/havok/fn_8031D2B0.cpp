#pragma force_active on
#pragma fp_contract on

struct Vec4 {
    float x, y, z, w;
};

struct Matrix {
    Vec4 row[4];
} __attribute__((aligned(16)));

struct Obj {
    char pad[0x68];
    Vec4* pos;
};

extern "C" void fn_8031D730(Obj* self, const Vec4* in, Matrix* out);
extern "C" void fn_8031D8FC(Obj* self, const Matrix* src);

extern "C" void fn_8031D2B0(Obj* self) {
    Matrix a;
    Matrix b;
    Vec4 d;
    Vec4 neg;
    Vec4 r;
    Vec4* m;
    float dp;
    float dq;

    m = self->pos;
    fn_8031D730(self, m, &a);
    d.x = a.row[0].x - self->pos->x;
    d.y = a.row[0].y - self->pos->y;
    d.z = a.row[0].z - self->pos->z;
    d.w = a.row[0].w - self->pos->w;
    dp = d.x * d.x + d.y * d.y + d.z * d.z;
    neg.x = -m->x;
    neg.y = -m->y;
    neg.z = -m->z;
    neg.w = -m->w;
    fn_8031D730(self, &neg, &b);
    r.x = b.row[0].x - self->pos->x;
    r.y = b.row[0].y - self->pos->y;
    r.z = b.row[0].z - self->pos->z;
    r.w = b.row[0].w - self->pos->w;
    dq = r.x * r.x + r.y * r.y + r.z * r.z;
    if (dp >= dq) {
        fn_8031D8FC(self, &a);
    } else {
        fn_8031D8FC(self, &b);
    }
}
