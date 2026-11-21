#pragma force_active on
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct In { char pad[0xC]; float w, x, y, z; };
extern "C" const float lbl_804102F0[32];
extern "C" V4* fn_802CDED4(const In* in, V4* out) {
    V4 v;
    v.x = in->x; v.y = in->y; v.z = in->z; v.w = in->w;
    const float* m = lbl_804102F0;
    V4* p = out;
    for (int i = 0; i < 4; i++) {
        V4 a, b;
        a.x = v.x * m[0]; a.y = v.y * m[1]; a.z = v.z * m[2]; a.w = v.w * m[3];
        p[0] = a;
        b.x = v.x * m[4]; b.y = v.y * m[5]; b.z = v.z * m[6]; b.w = v.w * m[7];
        p[1] = b;
        m += 8;
        p += 2;
    }
    return out;
}
