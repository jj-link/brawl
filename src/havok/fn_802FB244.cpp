#pragma force_active on

typedef void (*F)();

extern "C" {
void fn_802FB2E8();
void fn_802FB324();
void fn_802FB3A4();
void fn_802FB418();
void fn_802FB45C();
void fn_802FB460();
void fn_802FB464();
void fn_802CC214(void*, F*, int, int);

void fn_802FB244(void* p) {
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
    s.f[0] = fn_802FB2E8;
    s.h = fn_802FB464;
    s.g = 0;
    s.f[2] = fn_802FB324;
    s.f[3] = fn_802FB3A4;
    s.f[4] = fn_802FB418;
    s.f[5] = fn_802FB45C;
    s.a = 0;
    s.f[1] = fn_802FB460;
    s.c1 = 0;
    fn_802CC214(p, s.f, 7, 7);
}
}
