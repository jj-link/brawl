#pragma force_active on
#pragma fp_contract on

struct Vec4 {
    float x, y, z, w;
};

struct Matrix {
    float m[4][4];
} __attribute__((aligned(16)));

struct State {
    int a, b;
    char pad[0x18];
    Vec4 p;
    char pad30[0x70];
    Vec4 q;
    char padb0[0x80];
    Vec4 r;
};

extern "C" void fn_80287600(Matrix*, const Matrix*, const Matrix*);
extern "C" void fn_803198C8(State*, Vec4*, Vec4*, Matrix*, Vec4*);
extern const float lbl_805A4650;

extern "C" void fn_803154E4(
    Matrix* a, Matrix* b, Vec4* sa, Vec4* sb, State* s, Vec4* out, Vec4* out2)
{
    Matrix m;
    Vec4 v;
    Vec4 p;

    fn_80287600(&m, a, b);
    fn_803198C8(s, sa, sb, &m, &v);

    float x = v.x, y = v.y, z = v.z;
    float ox = z * a->m[2][0] + (x * a->m[0][0] + y * a->m[1][0]);
    float oy = z * a->m[2][1] + (x * a->m[0][1] + y * a->m[1][1]);
    float oz = z * a->m[2][2] + (x * a->m[0][2] + y * a->m[1][2]);
    out->x = ox;
    out->y = oy;
    out->z = oz;
    out->w = lbl_805A4650;

    if (s->a == 1) {
        p = s->p;
    } else if (s->b == 1) {
        float qz, qy, qx;
        qx = s->q.x;
        qy = s->q.y;
        qz = s->q.z;
        float qw = s->q.w;
        float w = v.w;
        float px = w * v.x + qx;
        float py = w * v.y + qy;
        float pz = w * v.z + qz;
        p.w = w * w + qw;
        p.x = px;
        p.y = py;
        p.z = pz;
    } else {
        p = s->r;
    }

    p.x = p.x - v.w * v.x;
    p.y = p.y - v.w * v.y;
    p.z = p.z - v.w * v.z;
    p.w = p.w - v.w * v.w;

    float dz = p.z - m.m[3][2];
    float dy = p.y - m.m[3][1];
    float dx = p.x - m.m[3][0];

    out2->x = dz * m.m[0][2] + (dx * m.m[0][0] + dy * m.m[0][1]);
    out2->y = dz * m.m[1][2] + (dx * m.m[1][0] + dy * m.m[1][1]);
    out2->z = dz * m.m[2][2] + (dx * m.m[2][0] + dy * m.m[2][1]);
    out2->w = lbl_805A4650;

    float ra = sa->w;
    float rb = sb->w;
    out->w = (v.w - ra) - rb;
}
