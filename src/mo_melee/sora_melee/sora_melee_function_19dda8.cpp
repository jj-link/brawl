#pragma force_active on
struct S {
    int w0;
    int w1;
    unsigned int a : 10;
    unsigned int b : 6;
    unsigned int c : 16;
};

extern "C" int fn_27_19DDA8(S* p) {
    return (int)(p->b << 26) >> 27;
}
