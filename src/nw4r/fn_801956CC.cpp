#pragma force_active on
typedef unsigned int u32;

extern float lbl_805A31F4;

struct Vec {
    float x, y, z;

    void set(float c, float b, float a) {
        x = a;
        y = b;
        z = c;
    }
};

struct Src {
    u32 flags;
    Vec v;
};

extern "C" void fn_801956CC(Src* src, Vec* dst) {
    if (src->flags & 8) {
        float k = lbl_805A31F4;
        dst->x = k;
        dst->y = k;
        dst->z = k;
        return;
    }

    dst->set(src->v.z, src->v.y, src->v.x);
}
