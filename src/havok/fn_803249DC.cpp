#pragma force_active on
#pragma fp_contract on
#include <types.h>

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct V3 { f32 x, y, z; };

extern const f32 lbl_805A47C8;
extern const f32 lbl_805A47CC;

static inline f32 dot3(const V4& a, const V4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

extern "C" void fn_803249DC(const V4* p, const V4* a, const V4* b, const V4* c, V3* out) {
    V4 cb;
    V4 ab;
    ab.x = a->x - b->x;
    ab.y = a->y - b->y;
    ab.z = a->z - b->z;
    ab.w = a->w - b->w;
    cb.x = c->x - b->x;
    cb.y = c->y - b->y;
    cb.z = c->z - b->z;
    cb.w = c->w - b->w;

    f32 aa = dot3(ab, ab);
    f32 cc = dot3(cb, cb);
    f32 ac = dot3(cb, ab);
    f32 det = aa * cc;
    f32 acac = ac * ac;
    det = det - acac;

    if (det > lbl_805A47C8) {
        f32 inv = lbl_805A47CC / det;
        V4 bp;
        bp.x = b->x - p->x;
        bp.y = b->y - p->y;
        bp.z = b->z - p->z;
        bp.w = b->w - p->w;
        f32 w0 = dot3(bp, ab);
        f32 w1 = dot3(bp, cb);
        f32 s = w1 * ac - cc * w0;
        f32 t = w0 * ac - aa * w1;
        det = det - s;
        det = det - t;
        out->x = inv * s;
        out->z = inv * t;
        out->y = inv * det;
        return;
    }

    V4 ca;
    ca.x = a->x - c->x;
    ca.y = a->y - c->y;
    ca.z = a->z - c->z;
    ca.w = a->w - c->w;
    f32 dd = dot3(ca, ca);

    if (aa >= cc) {
        if (dd >= aa) {
            out->y = lbl_805A47C8;
            if (dd > lbl_805A47C8) {
                V4 pc;
                pc.x = p->x - c->x;
                pc.y = p->y - c->y;
                pc.z = p->z - c->z;
                pc.w = p->w - c->w;
                f32 t = dot3(pc, ca) / dd;
                out->x = t;
                out->z = lbl_805A47CC - t;
            } else {
                out->x = lbl_805A47C8;
                out->z = out->x;
            }
        } else {
            V4 pb;
            pb.x = p->x - b->x;
            pb.y = p->y - b->y;
            pb.z = p->z - b->z;
            pb.w = p->w - b->w;
            out->z = lbl_805A47C8;
            f32 t = dot3(pb, ab) / aa;
            out->x = t;
            out->y = lbl_805A47CC - t;
        }
        return;
    }

    if (dd >= cc) {
        V4 pc;
        pc.x = p->x - c->x;
        pc.y = p->y - c->y;
        pc.z = p->z - c->z;
        pc.w = p->w - c->w;
        out->y = lbl_805A47C8;
        f32 t = dot3(pc, ca) / dd;
        out->x = t;
        out->z = lbl_805A47CC - t;
    } else {
        V4 pb;
        pb.x = p->x - b->x;
        pb.y = p->y - b->y;
        pb.z = p->z - b->z;
        pb.w = p->w - b->w;
        out->x = lbl_805A47C8;
        f32 t = dot3(pb, cb) / cc;
        out->z = t;
        out->y = lbl_805A47CC - t;
    }
}
