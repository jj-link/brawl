#pragma force_active on
typedef unsigned int u32;
typedef float f32;

struct Vec {
    f32 x, y, z;
    void set(f32 c, f32 b, f32 a) {
        x = a;
        y = b;
        z = c;
    }
};

struct Src {
    u32 flags;
    char pad0[0x24];
    f32 a;
    char pad1[0xC];
    f32 b;
    char pad2[0xC];
    f32 c;
};

extern f32 lbl_805A31F0;

extern "C" void fn_8019589C(Src* src, Vec* dst) {
    if (src->flags & 0x40) {
        f32 v = lbl_805A31F0;
        dst->x = v;
        dst->y = v;
        dst->z = v;
        return;
    }
    dst->set(src->c, src->b, src->a);
}
