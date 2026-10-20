#pragma force_active on
extern "C" int fn_27_1D0D24(int *p) {
    union {
        int v;
        struct { unsigned a : 6; signed b : 6; } f;
    } u;
    u.v = p[2];
    return u.f.b;
}
