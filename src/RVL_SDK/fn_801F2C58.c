#pragma force_active on
typedef unsigned int u32;

union U {
    u32 w;
    struct {
        u32 b0 : 28;
        u32 f2 : 2;
        u32 f1 : 2;
    } s;
};

void fn_801F2C58(u32* a, u32 b, u32 c) {
    union U u;
    u.w = *a;
    u.s.f1 = b;
    u.s.f2 = c;
    *a = u.w;
}
