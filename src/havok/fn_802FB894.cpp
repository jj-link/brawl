#pragma force_active on
typedef void (*F)();
extern "C" {
void fn_802FB948();
void fn_802FB9A4();
void fn_802FBE84();
void fn_802FBEF8();
void fn_802FBF38();
void fn_802FBF70();
void fn_802FBF74();
void fn_802FBF78();
void fn_802CC214(void*, F*, int, int);

void fn_802FB894(void* p) {
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
    s.b = 0;
    s.c = 0;
    s.c2 = 0;
    s.f[0] = fn_802FB948;
    s.h = fn_802FBF78;
    s.g = fn_802FB9A4;
    s.f[2] = fn_802FBE84;
    s.f[3] = fn_802FBEF8;
    s.f[4] = fn_802FBF38;
    s.f[5] = fn_802FBF70;
    s.a = 0;
    s.f[1] = fn_802FBF74;
    s.c1 = 0;
    fn_802CC214(p, s.f, 8, 6);
}
}
