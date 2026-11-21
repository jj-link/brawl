#include <types.h>
#pragma force_active on

extern "C" void fn_80162DF8(f32* out, const f32* m, const f32* box) {
    f32 s3, s2, s;
    f32 lx, ly, lz, hx, hy, hz;
    f32 c, d, e, f;

    lx = box[3] + box[0] * m[0];
    hx = box[3] + box[0] * m[3];
    c = box[1] * m[1];
    d = box[1] * m[4];
    e = box[2] * m[2];
    f = box[2] * m[5];
    if (lx > hx) {
        s = lx;
        lx = hx;
        hx = s;
    }
    if (c < d) {
        lx += c;
        hx += d;
    } else {
        lx += d;
        hx += c;
    }
    if (e < f) {
        lx += e;
        hx += f;
    } else {
        lx += f;
        hx += e;
    }

    ly = box[7] + box[4] * m[0];
    hy = box[7] + box[4] * m[3];
    c = box[5] * m[1];
    d = box[5] * m[4];
    e = box[6] * m[2];
    s2 = box[6] * m[5];
    if (ly > hy) {
        s = ly;
        ly = hy;
        hy = s;
    }
    if (c < d) {
        ly += c;
        hy += d;
    } else {
        ly += d;
        hy += c;
    }
    if (e < s2) {
        ly += e;
        hy += s2;
    } else {
        ly += s2;
        hy += e;
    }

    lz = box[11] + box[8] * m[0];
    hz = box[11] + box[8] * m[3];
    c = box[9] * m[1];
    d = box[9] * m[4];
    e = box[10] * m[2];
    s3 = box[10] * m[5];
    if (lz > hz) {
        s = lz;
        lz = hz;
        hz = s;
    }
    if (c < d) {
        lz += c;
        hz += d;
    } else {
        lz += d;
        hz += c;
    }
    if (e < s3) {
        lz += e;
        hz += s3;
    } else {
        lz += s3;
        hz += e;
    }

    out[0] = lx;
    out[1] = ly;
    out[2] = lz;
    out[3] = hx;
    out[4] = hy;
    out[5] = hz;
}
