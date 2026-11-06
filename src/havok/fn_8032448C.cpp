#pragma force_active on
#pragma fp_contract on
struct V { float x,y,z,w; } __attribute__((aligned(16)));
struct M {
    V a,b,c,d;
    M() {}
    M(const M& o) { *this = o; }
    M& operator=(const M& o) {
        a.x=o.a.x; a.y=o.a.y; a.z=o.a.z; a.w=o.a.w;
        b.x=o.b.x; b.y=o.b.y; b.z=o.b.z; b.w=o.b.w;
        c.x=o.c.x; c.y=o.c.y; c.z=o.c.z; c.w=o.c.w;
        d.x=o.d.x; d.y=o.d.y; d.z=o.d.z; d.w=o.d.w;
        return *this;
    }
};
extern "C" void fn_8032448C(const M* mat, const float* in, int count, float* out) {
    M n;
    M m = *mat;
    n = m;
    for (int i = 0; i < count; ++i) {
        int j = i * 4;
        float* dst = out + j;
        const float* src = in + j;
        float z = src[2], y = src[1], x = src[0];
        dst[0] = n.d.x + (x*n.a.x + y*n.b.x + z*n.c.x);
        dst[1] = n.d.y + (x*n.a.y + y*n.b.y + z*n.c.y);
        dst[2] = n.d.z + (x*n.a.z + y*n.b.z + z*n.c.z);
        dst[3] = n.d.w + (x*n.a.w + y*n.b.w + z*n.c.w);
    }
}