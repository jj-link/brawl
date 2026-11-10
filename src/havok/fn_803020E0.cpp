#pragma force_active on
typedef void (*F)();
extern "C" {
void fn_803009A4();
void fn_80300B30();
void fn_80300BAC();
void fn_80300BE8();
void fn_80300C30();
void fn_80300C6C();
void fn_80302270();
void fn_803021C0();
void fn_802CC214(void*, F*, int, int);

void fn_803020E0(void* p) {
    struct S {
        F f[6];
        int a;
        int b;
        int c;
        F g;
        F h;
        char c1;
        char c2;
    } s;

    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.f[0] = fn_803021C0;
    s.h = fn_80302270;
    s.g = fn_803009A4;
    s.f[2] = fn_80300B30;
    s.f[3] = fn_80300BAC;
    s.f[4] = fn_80300BE8;
    s.f[5] = fn_80300C30;
    s.f[1] = fn_80300C6C;
    s.c1 = 1;
    s.c2 = 1;
    fn_802CC214(p, s.f, 5, 1);
    fn_802CC214(p, s.f, 1, 5);
}
}
