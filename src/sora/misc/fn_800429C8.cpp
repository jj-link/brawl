#include <types.h>
#pragma force_active on

extern "C" void fn_8003DBA8(f32* v);
extern f32 lbl_805A17A8;

struct RawSeg {
    u32 a, b, c, d;
};

struct RawVec {
    u32 x, y;
};

struct Vec2 {
    f32 x, y;
};

extern "C" void fn_800429C8(f32* out, const f32* p, const f32* q) {
    f32 A[4];
    f32 B[4];
    f32 dxy[2];
    Vec2 v;
    Vec2 v2;
    Vec2 n;
    struct Line {
        f32 x, y, d;
        Line(const Vec2& n, f32 c) : x(n.x), y(n.y), d(-c) {}
    };
    f32 s0, s1;

    if (p[0] < p[2]) {
        *(RawSeg*)A = *(RawSeg*)p;
    } else {
        A[0] = p[2];
        A[1] = p[3];
        A[2] = p[0];
        A[3] = p[1];
    }
    if (q[0] < q[2]) {
        *(RawSeg*)B = *(RawSeg*)q;
    } else {
        B[0] = q[2];
        B[1] = q[3];
        B[2] = q[0];
        B[3] = q[1];
    }

    dxy[0] = A[2] - A[0];
    dxy[1] = A[3] - A[1];
    *(RawVec*)&v = *(RawVec*)dxy;
    *(RawVec*)&v2 = *(RawVec*)&v;
    n.x = -v2.y;
    n.y = v2.x;
    fn_8003DBA8((f32*)&n);

    Line line(n, n.x * A[0] + n.y * A[1]);
    s0 = line.d + (line.x * B[0] + line.y * B[1]);
    s1 = line.d + (line.x * B[2] + line.y * B[3]);

    if (s0 < lbl_805A17A8 && s1 < lbl_805A17A8) {
        out[0] = A[0];
        out[1] = A[1];
        out[2] = B[0];
        out[3] = B[1];
        out[4] = B[2];
        out[5] = B[3];
        out[6] = A[2];
        out[7] = A[3];
        return;
    }
    if (s0 > lbl_805A17A8 && s1 > lbl_805A17A8) {
        out[0] = B[0];
        out[1] = B[1];
        out[2] = A[0];
        out[3] = A[1];
        out[4] = A[2];
        out[5] = A[3];
        out[6] = B[2];
        out[7] = B[3];
        return;
    }
    if (s0 < lbl_805A17A8 && s1 > lbl_805A17A8) {
        out[0] = A[0];
        out[1] = A[1];
        out[2] = B[0];
        out[3] = B[1];
        out[4] = A[2];
        out[5] = A[3];
        out[6] = B[2];
        out[7] = B[3];
        return;
    }
    out[0] = B[0];
    out[1] = B[1];
    out[2] = A[0];
    out[3] = A[1];
    out[4] = B[2];
    out[5] = B[3];
    out[6] = A[2];
    out[7] = A[3];
}
