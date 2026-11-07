#pragma force_active on
#pragma fp_contract on
struct V { float x,y,z,w; } __attribute__((aligned(16)));
struct B { char pad[0x30]; V p; };
struct C { V a[3]; V b[3]; };
struct L { V p[3]; V wa, wb, t0, t1; };

extern "C" float fn_80294924(B* b0, B* b1, C* c, float s, float k) {
    L l;
    l.p[0].x = c->b[0].x * c->a[0].x; l.p[0].y = c->b[0].y * c->a[0].y;
    l.p[0].z = c->b[0].z * c->a[0].z; l.p[0].w = c->b[0].w * c->a[0].w;
    l.p[1].x = c->b[1].x * c->a[1].x; l.p[1].y = c->b[1].y * c->a[1].y;
    l.p[1].z = c->b[1].z * c->a[1].z; l.p[1].w = c->b[1].w * c->a[1].w;
    l.p[2].x = c->b[2].x * c->a[2].x; l.p[2].y = c->b[2].y * c->a[2].y;
    l.p[2].z = c->b[2].z * c->a[2].z; l.p[2].w = c->b[2].w * c->a[2].w;
    float wb = b1->p.w;
    float wa = b0->p.w;
    l.wa.x = wa; l.wa.y = wa; l.wa.z = wa; l.wa.w = wa;
    l.wb.x = wb; l.wb.y = wb; l.wb.z = wb; l.wb.w = wb;
    l.t0.x = l.wa.x * l.p[0].x; l.t0.y = l.wa.y * l.p[0].y; l.t0.z = l.wa.z * l.p[0].z; l.t0.w = l.wa.w * l.p[0].w;
    l.t1.x = l.wb.x * l.p[0].x; l.t1.y = l.wb.y * l.p[0].y; l.t1.z = l.wb.z * l.p[0].z; l.t1.w = l.wb.w * l.p[0].w;
    l.p[1].x *= b0->p.x; l.p[1].y *= b0->p.y; l.p[1].z *= b0->p.z; l.p[1].w *= l.wa.w;
    l.p[2].x *= b1->p.x; l.p[2].y *= b1->p.y; l.p[2].z *= b1->p.z; l.p[2].w *= l.wb.w;
    l.t0.x = l.t0.x + l.t1.x; l.t0.y = l.t0.y + l.t1.y; l.t0.z = l.t0.z + l.t1.z; l.t0.w = l.t0.w + l.t1.w;
    l.p[1].x = (l.p[1].x + l.p[2].x);
    l.p[1].y = (l.p[1].y + l.p[2].y);
    l.p[1].z = (l.p[1].z + l.p[2].z);
    l.p[1].w = (l.p[1].w + l.p[2].w);
    l.p[1].x = l.p[1].x + l.t0.x;
    l.p[1].y = l.p[1].y + l.t0.y;
    l.p[1].z = l.p[1].z + l.t0.z;
    l.p[1].w = l.p[1].w + l.t0.w;
    float d = l.p[1].z + (l.p[1].x + l.p[1].y);
    float f = d * k;
    float m0 = c->a[2].w;
    float m1 = c->b[2].w;
    float inv = s / (m0 * m1 - f * f);
    c->a[2].w = m1 * inv;
    c->b[2].w = m0 * inv;
    return -f * inv;
}
