#pragma force_active on
typedef void (*F)();
extern "C" {
void fn_802CAB20();
void fn_802CABFC();
void fn_802CAC4C();
void fn_802CAC60();
void fn_802CAC80();
void fn_802CAC98();
void fn_802CACB0();
void fn_802CACC8();
void fn_802CACE0();
void fn_802CC214(void*, F*, int, int);

void fn_802CAA50(void* p) {
    struct S {
        F f[9];
        int a;
        F h;
        char c1;
        char c2;
    } s;

    s.c2 = 0;
    s.f[4] = fn_802CACC8;
    s.f[5] = fn_802CACE0;
    s.f[3] = fn_802CACB0;
    s.f[0] = fn_802CAB20;
    s.h = fn_802CABFC;
    s.a = 0;
    s.f[2] = 0;
    s.f[1] = fn_802CAC4C;
    s.f[6] = fn_802CAC60;
    s.f[7] = fn_802CAC80;
    s.f[8] = fn_802CAC98;
    s.c1 = 1;
    fn_802CC214(p, s.f, -1, -1);
}
}
