#pragma force_active on

struct S {
    unsigned char a[24];
    unsigned char b[8];
    unsigned int j[8];
    unsigned char k[4];
    float l;
    unsigned int m;
    float n;
    float p;
    float o;
    unsigned int q;
    unsigned int r;
    unsigned int s;
};

extern "C" void fn_80160E3C(S*, int, int, int, float, float, float);
extern "C" void fn_8015ECB8(void*, int);

extern "C" void fn_80160328(const S* src, int a, int b, int c, float e, float f, float d) {
    S local;
    local = *src;
    fn_80160E3C(&local, a, b, c, local.n, local.l, d);
    fn_8015ECB8(&local, 0);
}
