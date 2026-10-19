#pragma force_active on
struct S {
    int a;
    unsigned char b;
    int c;
    int d;
};

extern "C" void fn_113_242AC(S* dst, S* src) {
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
}
