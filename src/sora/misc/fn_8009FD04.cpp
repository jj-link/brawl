#pragma force_active on
struct H { char pad[0x34]; float f34; };
struct A { char pad[0x94]; unsigned char flags; char pad2[0xB0-0x95]; float b0; float b4; char pad3[0x138-0xB8]; H* h; };
struct S { char pad[0x30]; float f30; };
struct I { int x, y; };
struct Q { I a, b; };
union R { struct { float a, b, c, d; } f; Q q; };
struct CC { char pad[0x158]; Q q; };
extern "C" {
void fn_800A19B4(A*, S*, int, float);
void fn_800A1754(A*, S*, int, float);
void fn_800A1E94(A*, void*, S*, R*, float, float, float, float);
CC* getInstance__16CameraControllerFv();
extern const float lbl_805A1E84;
extern const float lbl_805A1EA4;
void fn_8009FD04(A* a, int p1, S* s, int p3, float f0, float f1) {
    float v = lbl_805A1E84;
    if (a->h) v = a->h->f34;
    v *= f1;
    fn_800A19B4(a, s, p1, v);
    fn_800A1754(a, s, p3, v);
    if (a->flags & 1) {
        R r;
        r.q = getInstance__16CameraControllerFv()->q;
        if ((a->flags >> 7) & 1) {
            float t = a->b0, u = a->b4;
            r.f.a -= t; r.f.b -= t; r.f.c -= u; r.f.d -= u;
        }
        fn_800A1E94(a, (char*)s + 0x18, s, &r, lbl_805A1EA4 * s->f30, f0, lbl_805A1E84, lbl_805A1E84);
    }
}
}
